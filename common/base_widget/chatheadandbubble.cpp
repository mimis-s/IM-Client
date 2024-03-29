#include "chatheadandbubble.h"
#include <qdebug.h>
#include <QHBoxLayout>
#include <QVBoxLayout>

ChatHeadAndBubble::ChatHeadAndBubble(QWidget *parent,ENUM_BubbleOrient orient, QVector<MessageFileRecap> vecMessageFileRecap, QString headPath, int64_t messageID) : QWidget(parent)
{
    m_bubbleOrient = orient;
    m_vecMessageFileRecap = vecMessageFileRecap;
    m_messageID = messageID;

    m_pLbHead = new CircleLabel(this, ENUM_CircleStyle::ENUM_Solid);
    m_pLbHead->SetImgPath(headPath);
    m_pLbHead->SetCircleLabelHide(false);
    m_pLbHead->setMinimumSize(50, 50);
    m_pLbHead->setMaximumSize(50, 50);

    m_pChatBubble = new ChatBubble(this, m_bubbleOrient, vecMessageFileRecap);

    if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleLeft)
    {
        QHBoxLayout *pLayout = new QHBoxLayout(this);
        pLayout->addWidget(m_pLbHead);
        pLayout->addWidget(m_pChatBubble);

//        m_pLbHead->setGeometry(0,0,50, 50);
//        m_pChatBubble->move(55, 0);

    }else{
//        m_pChatBubble->move(this->width() - m_pChatBubble->width() - 55,0);
//        m_pLbHead->setGeometry(m_pChatBubble->width(), 0, 50, 50);
        QHBoxLayout *pLayout = new QHBoxLayout(this);
        pLayout->addWidget(m_pChatBubble);
        pLayout->addWidget(m_pLbHead);
    }

    this->setMinimumSize(100, 100);
    connect(m_pChatBubble, SIGNAL(sig_resize(int)), this, SLOT(slot_bubbleResize(int)));

}

QSize ChatHeadAndBubble::GetMinSize()
{
    return QSize(120,70);
}

// 聊天气泡的长度随widget变化而变化,但是不会超过气泡自己的最大最小值
void ChatHeadAndBubble::resizeEvent(QResizeEvent * event)
{
//    int iWidth = qMax(qMin(this->width() - 65, m_pChatBubble->GetMaxWidth()), m_pChatBubble->GetMinWidth());
//    iWidth = qMin(iWidth, QFontMetrics(m_pChatBubble->font()).width(m_sText) + 50);
//    m_pChatBubble->resize(iWidth, m_pChatBubble->height());
//    m_pChatBubble->

//    if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleRight)
//    {
//        m_pLbHead->setGeometry(width() - 55, 0, 50, 50);
//        m_pChatBubble->move(this->width() - m_pChatBubble->width() - 55,0);
//    }
//    this->resize(100, 100);

    QWidget::resizeEvent(event);
}

// widget高度随着聊天气泡变化而变化
void ChatHeadAndBubble::slot_bubbleResize(int iHeight)
{
    iHeight = iHeight + 20;
//    // 气泡高度和头像高度取一个最大值
    iHeight = iHeight > m_pLbHead->height()?iHeight:m_pLbHead->height();

    this->resize(this->width(), iHeight);
    emit sig_changeHeight();
}
