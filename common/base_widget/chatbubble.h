#ifndef CHATBUBBLE_H
#define CHATBUBBLE_H

#include <QWidget>
#include <QFont>

// 气泡朝向(朝左则开口在左上角, 朝右则开口在右上角)
enum ENUM_BubbleOrient {
    ENUM_BubbleLeft = 0,
    ENUM_BubbleRight = 1,
};

class ChatBubble : public QWidget
{
    Q_OBJECT
public:
    explicit ChatBubble(QWidget *parent = nullptr, ENUM_BubbleOrient orient = ENUM_BubbleOrient::ENUM_BubbleRight, QString bubbleText = "");

    void SetBubbleOrient(ENUM_BubbleOrient orient);
    int GetMaxWidth();
    int GetMinWidth();

signals:
    void sig_resize(int iHeight);
protected:
    void paintEvent(QPaintEvent *e);

private:
    ENUM_BubbleOrient m_bubbleOrient;
    QString m_sBubbleText;

    int m_iMaxWidth;
    int m_iMinWidth;
};

#endif // CHATBUBBLE_H
