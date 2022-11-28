#include "chatbox.h"
#include "common/base_widget/chatbubble.h"
#include <qdebug.h>
#include "common/base_widget/chatheadandbubble.h"
#include <QAbstractItemView>
#include "../socket/socket.h"
#include "../commonproto/home_chat.pb.h"
#include "../define/define.h"
#include "../../src/login/logininfo.h"
#include "../log/im_log.h"

ChatBox::ChatBox(QWidget *parent, ChatShortFrameData data) : QWidget(parent)
{
    m_chatShortFrameData = data;

    QVBoxLayout *pVBoxlayout = new QVBoxLayout(this);

    // 上面
    QHBoxLayout *pUpHBoxLayout = new QHBoxLayout();
    // 头像,昵称
    m_pLbHead = new CircleLabel(this, ENUM_CircleStyle::ENUM_Solid);
    m_pLbHead->setMinimumSize(60, 60);
    m_pLbHead->SetImgPath(m_chatShortFrameData.m_HeadPath);

    m_pLbName = new QLabel(m_chatShortFrameData.m_Name, this);

    // 电话,视频
    m_pBtnPhone = new QPushButton();
    m_pBtnPhone->setIcon(QIcon(":/img/im_chat_phone"));
    m_pBtnPhone->setIconSize(QSize(40,40));
    m_pBtnPhone->setStyleSheet("max-width:40px; min-width:40px;"
                             "max-height:40px; min-height:40px;"
                             "border-radius:20px;");

    m_pBtnVideo = new QPushButton();
    m_pBtnVideo->setIcon(QIcon(":/img/im_chat_videoChat"));
    m_pBtnVideo->setIconSize(QSize(40,40));
    m_pBtnVideo->setStyleSheet("max-width:40px; min-width:40px;"
                             "max-height:40px; min-height:40px;"
                             "border-radius:20px;");

    pUpHBoxLayout->addWidget(m_pLbHead);
    pUpHBoxLayout->addWidget(m_pLbName);
    pUpHBoxLayout->addStretch();
    pUpHBoxLayout->addWidget(m_pBtnPhone);
    pUpHBoxLayout->addWidget(m_pBtnVideo);

    // 中间
    m_pMiddleListWidget = new QListWidget(this);
    m_pMiddleListWidget->setStyleSheet("background-color:white;");
    m_pMiddleListWidget->setResizeMode(QListView::Adjust);
    m_pMiddleListWidget->setAutoScroll(true);
    m_pMiddleListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pMiddleListWidget->setSizeAdjustPolicy(QListWidget::AdjustToContents);

    // 下面
    QWidget *pDownWidget = new QWidget();

    QHBoxLayout *pDownHBoxLayout = new QHBoxLayout(pDownWidget);
    // 表情,发送框,发送按钮
    m_pBtnEmoj = new QPushButton(pDownWidget);
    m_pBtnEmoj->setIcon(QIcon(":/img/im_chat_emoj"));
    m_pBtnEmoj->setIconSize(QSize(40,40));
    m_pBtnEmoj->setStyleSheet("max-width:40px; min-width:40px;"
                             "max-height:40px; min-height:40px;"
                             "border-radius:20px;");
    m_pTextInput = new QTextEdit();
    m_pTextInput->setFont(QFont("", 16, QFont::Bold, true));
    m_pBtnSend = new QPushButton(tr(u8"发送"), pDownWidget);

    m_pBtnEmoj->setMinimumHeight(40);
    m_pTextInput->setMinimumHeight(40);
    m_pBtnSend->setMinimumHeight(40);

    m_pBtnEmoj->setMaximumHeight(40);
    m_pTextInput->setMaximumHeight(40);
    m_pBtnSend->setMaximumHeight(40);


    pDownHBoxLayout->addWidget(m_pBtnEmoj);
    pDownHBoxLayout->addWidget(m_pTextInput);
    pDownHBoxLayout->addWidget(m_pBtnSend);

    pVBoxlayout->addLayout(pUpHBoxLayout, 2);
    pVBoxlayout->addWidget(m_pMiddleListWidget, 7);
    pVBoxlayout->addWidget(pDownWidget, 1);

    connect(m_pBtnSend, SIGNAL(clicked()), this, SLOT(slot_btnSendClick()));
}

void ChatBox::slot_btnSendClick()
{
    if (m_pTextInput->toPlainText().trimmed() != "")
    {
        AddMessage(true, m_pTextInput->toPlainText(), m_chatShortFrameData.m_HeadPath);

        im_home_proto::ChatSingleReq *chatSingleReq = new im_home_proto::ChatSingleReq;

        im_home_proto::ChatMessage *chatMessage = new im_home_proto::ChatMessage;
        chatMessage->set_senderid(LoginInfo::Instance()->GetClientUserInfo()->userid());
        chatMessage->set_receiverid(m_chatShortFrameData.m_FriendID);
        chatMessage->set_messageid(1);
        chatMessage->set_messagetype(im_home_proto::MessageType_Enum::EnumTextType);
        chatMessage->set_sendtimestamp(QDateTime::currentDateTime().toTime_t());
        chatMessage->set_messagestatus(im_home_proto::MessageStatus_Enum::EnumSend);

        QString inputStr = m_pTextInput->toPlainText();
        chatMessage->set_data(inputStr.toStdString());

        chatSingleReq->set_allocated_data(chatMessage);

        IMLog::Instance()->Info(QString("send chatSingleReq %1").arg(MessageTag_ChatSingle.Req));

        Socket::Instance()->SendMessage(MessageTag_ChatSingle.Req, chatSingleReq->SerializeAsString());

        m_pTextInput->clear();
    }
}

void ChatBox::AddMessage(bool bSelf, QString sMessage, QString sHeadPath)
{
    if (bSelf) {
        QListWidgetItem *Item_1 = new QListWidgetItem(m_pMiddleListWidget);
        Item_1->setFlags(Item_1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);

        // 头像 聊天气泡

        ChatHeadAndBubble *pHeadAndBubble = new ChatHeadAndBubble(m_pMiddleListWidget, ENUM_BubbleRight, sMessage, sHeadPath);
        Item_1->setSizeHint(pHeadAndBubble->GetMinSize());

        connect(pHeadAndBubble, &ChatHeadAndBubble::sig_changeHeight, [Item_1, pHeadAndBubble]{
            Item_1->setSizeHint(pHeadAndBubble->size());
        });

        m_pMiddleListWidget->setItemWidget(Item_1, pHeadAndBubble);
    }else{
        QListWidgetItem *Item_1 = new QListWidgetItem(m_pMiddleListWidget);
        Item_1->setFlags(Item_1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);

        // 头像 聊天气泡

        ChatHeadAndBubble *pHeadAndBubble = new ChatHeadAndBubble(m_pMiddleListWidget, ENUM_BubbleLeft, sMessage, sHeadPath);
        Item_1->setSizeHint(pHeadAndBubble->GetMinSize());

        connect(pHeadAndBubble, &ChatHeadAndBubble::sig_changeHeight, [Item_1, pHeadAndBubble]{
            Item_1->setSizeHint(pHeadAndBubble->size());
        });

        m_pMiddleListWidget->setItemWidget(Item_1, pHeadAndBubble);
    }

}
