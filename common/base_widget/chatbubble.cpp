#include "chatbubble.h"
#include <QPainter>
#include <QLabel>
#include <QFontMetrics>
#include <QDebug>

ChatBubble::ChatBubble(QWidget *parent, ENUM_BubbleOrient orient, QString bubbleText) : QWidget(parent)
{
    m_iMaxWidth = 360;
    m_iMinWidth = 60;
    this->setMinimumSize(m_iMinWidth, 60);
    this->setMaximumSize(m_iMaxWidth, 6000);
    m_bubbleOrient = orient;
    m_sBubbleText = bubbleText;
}

void ChatBubble::SetBubbleOrient(ENUM_BubbleOrient orient)
{
    m_bubbleOrient = orient;
}

int ChatBubble::GetMaxWidth()
{
    return m_iMaxWidth;
}

int ChatBubble::GetMinWidth()
{
    return m_iMinWidth;
}

void ChatBubble::paintEvent(QPaintEvent *e)
{
    QFont font("", 16, QFont::Bold, true);

    // 获取文字的长度
    QString sNewText;
    QString sTempText;
    int iTextLen = width() - 33;

    int iHeight = 20;
    bool bHanzi = false;

    for (int i = 0; i < m_sBubbleText.size(); i++)
    {
        if (m_sBubbleText[i] > 128 || m_sBubbleText[i] < 0){
            bHanzi = true;
        }

        if (QFontMetrics(font).width(sTempText + m_sBubbleText[i]) >= iTextLen)
        {
            sNewText += "\n";
            if (bHanzi) {
                iHeight += QFontMetrics(font).height() + 5;
            }else{
                iHeight += QFontMetrics(font).height() - 2;
            }
            sTempText = "";
            bHanzi = false;
        }
        sNewText += m_sBubbleText[i];
        sTempText += m_sBubbleText[i];
    }

    if (iHeight + 40 != height())
    {
//        resize(iBoxLen + 20, iHeight + 40);
        qDebug() << "height:" << iHeight + 40;
        emit sig_resize(iHeight + 40);
    }

    QRectF rectangle(10, 10, width() - 20, iHeight + 20);

    QPainter painter(this);
    painter.setRenderHint( QPainter::Antialiasing, true );
    QPen pen;
    pen.setColor(QColor(173,216,67));
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(173,216,67)));
    painter.drawRoundedRect(rectangle,10,10);

    if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleLeft) {
        QPointF points[3] = {
           QPointF(0, 33),
           QPointF(11, 28),
           QPointF(11, 38),
       };
       painter.drawPolygon(points, 3);
    }
    else if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleRight) {
        QPointF points_2[3] = {
           QPointF(this->width(), 33),
           QPointF(this->width()-11, 28),
           QPointF(this->width()-11, 38),
       };
       painter.drawPolygon(points_2, 3);
    }

    // 绘制文字
    painter.setPen(QColor(Qt::black));
    painter.setFont(font);


    QRectF rect(20, 16, width(), height());
    painter.drawText(rect, 0, sNewText);//字体居中

//    if (iHeight + 40 != height()){
//        resize(width(), iHeight + 40);
//    }
}
