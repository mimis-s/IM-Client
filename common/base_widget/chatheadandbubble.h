#ifndef CHATHEADANDBUBBLE_H
#define CHATHEADANDBUBBLE_H

#include <QWidget>
#include "chatbubble.h"
#include "circlelabel.h"

class ChatHeadAndBubble : public QWidget
{
    Q_OBJECT
public:
    explicit ChatHeadAndBubble(QWidget *parent = nullptr, ENUM_BubbleOrient orient = ENUM_BubbleOrient::ENUM_BubbleRight, QString sText = "404", QString headPath = "", int64_t messageID = 0);

    QSize GetMinSize();

    int64_t GetMessageID() {
        return m_messageID;
    }

protected:
    void resizeEvent(QResizeEvent * event);
signals:
    // 高度变化
    void sig_changeHeight();
public slots:
    void slot_bubbleResize(int iHeight);

private:
    CircleLabel *m_pLbHead;
    ChatBubble *m_pChatBubble;

    QSize m_sMinSize;
    QString m_sText;

    ENUM_BubbleOrient m_bubbleOrient;
     int64_t m_messageID;
};

#endif // CHATHEADANDBUBBLE_H
