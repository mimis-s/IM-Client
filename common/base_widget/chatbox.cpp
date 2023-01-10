#include "chatbox.h"
#include "common/base_widget/chatbubble.h"
#include <qdebug.h>
#include <QAbstractItemView>
#include "../socket/socket.h"
#include "../commonproto/home_chat.pb.h"
#include "../define/define.h"
#include "../../src/global/userinfo.h"
#include "../../src/global/chathistory.h"
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

    AddOneQueryHistoryBtn();
}

// 添加一个查询历史记录的按钮(类似于qq那个在聊天框中的刷新按钮)
void ChatBox::AddOneQueryHistoryBtn()
{
    QListWidgetItem *Item_1 = new QListWidgetItem();
    Item_1->setFlags(Item_1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    QPushButton *pBtnQuery = new QPushButton(tr(u8"刷新"), m_pMiddleListWidget);
    pBtnQuery->resize(50, 30);
    Item_1->setSizeHint(pBtnQuery->sizeHint());

    m_pMiddleListWidget->insertItem(0, Item_1);
    m_pMiddleListWidget->setItemWidget(Item_1, pBtnQuery);

    connect(pBtnQuery, SIGNAL(clicked()), this, SLOT(slot_btnQueryHistoryClick()));
}

void ChatBox::slot_btnQueryHistoryClick()
{
    std::map<int64_t, LocalChatHistoryInfo> mapChatHistory = ChatHistory::Instance()->GetHistoryChat(m_chatShortFrameData.m_FriendID, m_maxMessageHistoryID);

    for(auto history : mapChatHistory) {
        im_home_proto::ChatMessage chatMessage;
        chatMessage.set_senderid(history.second.SenderID);
        chatMessage.set_receiverid(history.second.ReceiverID);
        chatMessage.set_messageid(history.second.MessageID);
        chatMessage.set_messagetype(im_home_proto::MessageType_Enum(history.second.MessageType));
        chatMessage.set_messagestatus(im_home_proto::MessageStatus_Enum(history.second.MessageStatus));
        chatMessage.set_data(history.second.messageData.toStdString());
        InsertMessage(chatMessage);
    }


    if (mapChatHistory.begin() != mapChatHistory.end()) {
        m_maxMessageHistoryID = mapChatHistory.begin()->second.MessageID - 1;
    }

    //
//    m_pMiddleListWidget->removeItemWidget()
    QList<QPushButton*> itemList = m_pMiddleListWidget->findChildren<QPushButton*>();  // 获取所有的QChatHeadAndBubble
    QPushButton *pBtn=qobject_cast<QPushButton *>(sender());

    for (int i = 0; i < m_pMiddleListWidget->count(); i++) {
        QWidget *pWidget = m_pMiddleListWidget->itemWidget(m_pMiddleListWidget->item(i));
        if (pBtn == (QPushButton *)pWidget) {
            m_pMiddleListWidget->takeItem(i);
            break;
        }
    }

    AddOneQueryHistoryBtn();
}

void ChatBox::InsertMessage(const im_home_proto::ChatMessage pMessage)
{
    auto funcInsert = [](const im_home_proto::ChatMessage pMessage, QListWidget *listWidget, ChatHeadAndBubble* chatBubble){

        ENUM_BubbleOrient orient;
        int64_t messageSender = 0;
        if (UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID == pMessage.senderid()) {
            orient = ENUM_BubbleRight;
            messageSender = pMessage.senderid();
        }else{
            orient = ENUM_BubbleLeft;
            messageSender = pMessage.receiverid();
        }

        QListWidgetItem *Item_1 = new QListWidgetItem();
        Item_1->setFlags(Item_1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);

        // 头像 聊天气泡
        ChatHeadAndBubble *pHeadAndBubble = new ChatHeadAndBubble(listWidget, orient,
                                                                  QString::fromStdString(pMessage.data()),
                                                                  UserInfo::Instance()->GetUserHeadPath(messageSender),
                                                                  pMessage.messageid());
        Item_1->setSizeHint(pHeadAndBubble->GetMinSize());

        connect(pHeadAndBubble, &ChatHeadAndBubble::sig_changeHeight, [Item_1, pHeadAndBubble]{
            Item_1->setSizeHint(pHeadAndBubble->size());
        });

        int temp = listWidget->count();
        if (chatBubble != nullptr) {
            for (int i = 0; i < listWidget->count(); i++) {
                ChatHeadAndBubble *bubble = (ChatHeadAndBubble *)listWidget->itemWidget(listWidget->item(i));
                if (bubble == chatBubble) {
                    temp = i;
                    break;
                }
            }
        }

        listWidget->insertItem(temp, Item_1);
        listWidget->setItemWidget(Item_1, pHeadAndBubble);
    };

    // 插入一条数据
    QList<ChatHeadAndBubble*> itemList = m_pMiddleListWidget->findChildren<ChatHeadAndBubble*>();  // 获取所有的QChatHeadAndBubble

    if (itemList.size() == 0) {
        funcInsert(pMessage, m_pMiddleListWidget, nullptr);
        return;
    }


    bool bInsert = false;
    int64_t maxMessageID = 0;
    for(int i = 0; i < itemList.size(); i++) {
        if (i == 0) {
            if (pMessage.messageid() < itemList[i]->GetMessageID()) {
                funcInsert(pMessage, m_pMiddleListWidget, itemList[i]);
                bInsert = true;
                break;
            }
        }else{
            if (pMessage.messageid() > itemList[i - 1]->GetMessageID() && pMessage.messageid() < itemList[i]->GetMessageID()) {
                funcInsert(pMessage, m_pMiddleListWidget, itemList[i]);
                bInsert = true;
                break;
            }
        }
        maxMessageID = maxMessageID > itemList[i]->GetMessageID()? maxMessageID: itemList[i]->GetMessageID();
    }
    if (!bInsert && maxMessageID != pMessage.messageid()) {
        funcInsert(pMessage, m_pMiddleListWidget, nullptr);
    }
}

void ChatBox::slot_btnSendClick()
{
    if (m_pTextInput->toPlainText().trimmed() != "")
    {
        im_home_proto::ChatSingleReq *chatSingleReq = new im_home_proto::ChatSingleReq;

        im_home_proto::ChatMessage *chatMessage = new im_home_proto::ChatMessage;
        chatMessage->set_senderid(UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID);
        chatMessage->set_receiverid(m_chatShortFrameData.m_FriendID);
        chatMessage->set_messagetype(im_home_proto::MessageType_Enum::EnumTextType);
        chatMessage->set_sendtimestamp(QDateTime::currentDateTime().toTime_t());
        chatMessage->set_messagestatus(im_home_proto::MessageStatus_Enum::EnumSend);

        QString inputStr = m_pTextInput->toPlainText();
        chatMessage->set_data(inputStr.toStdString());

        chatSingleReq->set_allocated_data(chatMessage);

        IMLog::Instance()->Info(QString("send chatSingleReq %1").arg(MessageTag_ChatSingle.Req));

        char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_ChatSingle.Req, MessageTag_ChatSingle.Res, chatSingleReq->SerializeAsString());

        im_home_proto::ChatSingleRes *chatSingleRes = new im_home_proto::ChatSingleRes;
        chatSingleRes->ParseFromString(recvMessage);

        AddMessage(chatSingleRes->data());

        m_pTextInput->clear();
    }
}

void ChatBox::AddMessage(const im_home_proto::ChatMessage &pMessage)
{

    ENUM_BubbleOrient orient;
    int64_t messageSender = 0;
    if (UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID == pMessage.senderid()) {
        orient = ENUM_BubbleRight;
        messageSender = pMessage.senderid();
    }else{
        orient = ENUM_BubbleLeft;
        messageSender = pMessage.receiverid();
    }
    QListWidgetItem *Item_1 = new QListWidgetItem(m_pMiddleListWidget);
    Item_1->setFlags(Item_1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);

    // 头像 聊天气泡
    ChatHeadAndBubble *pHeadAndBubble = new ChatHeadAndBubble(m_pMiddleListWidget, orient,
                                                              QString::fromStdString(pMessage.data()),
                                                              UserInfo::Instance()->GetUserHeadPath(messageSender),
                                                              pMessage.messageid());
    Item_1->setSizeHint(pHeadAndBubble->GetMinSize());

    connect(pHeadAndBubble, &ChatHeadAndBubble::sig_changeHeight, [Item_1, pHeadAndBubble]{
        Item_1->setSizeHint(pHeadAndBubble->size());
    });

    m_pMiddleListWidget->setItemWidget(Item_1, pHeadAndBubble);
}
