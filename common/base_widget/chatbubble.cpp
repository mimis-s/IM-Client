#include "chatbubble.h"
#include <QPainter>
#include <QLabel>
#include <QFontMetrics>
#include <QDebug>

ChatBubble::ChatBubble(QWidget *parent, ENUM_BubbleOrient orient, QVector<MessageFileRecap> vecMessageFileRecap) : QWidget(parent)
{
    m_iMaxWidth = 360;
    m_iMinWidth = 60;
//    this->setMinimumSize(m_iMinWidth, 60);
//    this->setMaximumSize(m_iMaxWidth, 6000);
    m_bubbleOrient = orient;
    m_vecMessageFileRecap = vecMessageFileRecap;
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

int getContentWidth(QFont font, QString str)
{
    QFontMetrics drugNameFmContent(font);
    QRect recContent_drugName = drugNameFmContent.boundingRect(str);
    int nDrugNameWidth = recContent_drugName.width();
    return nDrugNameWidth;
}

int getContentHeight(QFont font, QString str)
{
    QFontMetrics drugNameFmContent(font);
    QRect recContent_drugName = drugNameFmContent.boundingRect(str);
    int nDrugNametHeight = recContent_drugName.height();
    return nDrugNametHeight;
}


void ChatBubble::paintEvent(QPaintEvent *e)
{

    int iMaxWidth = m_iMaxWidth;
    if (m_iMaxWidth > width() - 30) {
        iMaxWidth = width() - 30;
    }

    QFont font("", 16, QFont::Bold, true);

    // 获取文字的长度
    QString sNewText;
    QString sTempText;
//    int iTextLen = width();

//    int iHeight = 20;
//    bool bHanzi = false;
    std::map<int, int> mapLineHeight; // 每一行的高度
    std::map<MessageFileRecap, int> mapMessageLine;

    int iLine = 0;
    int iBubbeWight = 0; // 气泡宽度
    int iTempWight = 0;

    for (int i = 0; i < m_vecMessageFileRecap.size(); i++)
    {
        // 查找当前位置是否插入文件
        int curHeight = 0;
        int curWight = 0;
        if (m_vecMessageFileRecap[i].MessageFileType == 1) {
            // 文本
            curHeight = getContentHeight(font, m_vecMessageFileRecap[i].FileData);
            curWight = getContentWidth(font, m_vecMessageFileRecap[i].FileData);
        }
        if (m_vecMessageFileRecap[i].MessageFileType == 2) {
            // 图片
            QImage img(m_vecMessageFileRecap[i].FileLocalPath);
            img = img.scaled(QSize(200,200), Qt::KeepAspectRatio);
            curHeight = img.height();
            curWight = img.width();
        }
        if (m_vecMessageFileRecap[i].MessageFileType == 3) {
            // 文件...
        }

        // 宽度
        if (iTempWight != 0 && iTempWight + curWight > iMaxWidth) {
            iLine++;
            iTempWight = 0;
            i--;
        }else{
            iTempWight += curWight;
            // 高度
            mapLineHeight[iLine] = mapLineHeight[iLine] < curHeight?curHeight:mapLineHeight[iLine];
            iBubbeWight = iBubbeWight < iTempWight? iTempWight:iBubbeWight;
        }
    }

   int iBubbeHeight = 0;
   for (auto line : mapLineHeight)
   {
       iBubbeHeight += line.second;
   }
   if (m_vecMessageFileRecap.size() == 0) {
       iBubbeWight = 20;
       iBubbeHeight = 20;
   }

    QRectF rectangleBubble(10, 10, iBubbeWight + 20, iBubbeHeight + 20); // 气泡位置大小，内容

    if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleRight) {
        rectangleBubble.setRect(width() - iBubbeWight - 31, 10, iBubbeWight + 20, iBubbeHeight + 20);
    }

    QRectF rectangleData(rectangleBubble.x() + 10, rectangleBubble.y() + 10, rectangleBubble.width() - 10, rectangleBubble.height() - 10); // 气泡位置大小，内容

    QPainter painter(this);
    painter.setRenderHint( QPainter::Antialiasing, true );
    QPen pen;
    pen.setColor(QColor(173,216,67));
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(173,216,67)));
    painter.drawRoundedRect(rectangleBubble,10,10);

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

    iTempWight = 0;
    int iTempHeight = 0;
    iLine = 0;

    for (int i = 0; i < m_vecMessageFileRecap.size(); i++)
    {
        // 查找当前位置是否插入文件
        int curHeight = 0;
        int curWight = 0;
        if (m_vecMessageFileRecap[i].MessageFileType == 1) {
            // 文本
            curHeight = getContentHeight(font, m_vecMessageFileRecap[i].FileData);
            curWight = getContentWidth(font, m_vecMessageFileRecap[i].FileData);
        }
        if (m_vecMessageFileRecap[i].MessageFileType == 2) {
            // 图片
            QImage img(m_vecMessageFileRecap[i].FileLocalPath);
            img = img.scaled(QSize(200,200), Qt::KeepAspectRatio);
            curHeight = img.height();
            curWight = img.width();
        }
        if (m_vecMessageFileRecap[i].MessageFileType == 3) {
            // 文件...
        }

        // 宽度
        if (iTempWight != 0 && iTempWight + curWight > iMaxWidth) {
            iTempWight = 0;
            i--;
            iTempHeight += mapLineHeight[iLine];
            iLine++;
        }else{

            int x = rectangleData.x() + iTempWight;
            int y = rectangleData.y() + iTempHeight + (mapLineHeight[iLine] - curHeight);
            QRectF rect(x, y, curWight, curHeight);
            if (m_vecMessageFileRecap[i].MessageFileType == 1) {
                // 文本
                painter.drawText(rect, 0, m_vecMessageFileRecap[i].FileData);//字体居中
            }

            if (m_vecMessageFileRecap[i].MessageFileType == 2) {

                QImage img(m_vecMessageFileRecap[i].FileLocalPath);
                img = img.scaled(QSize(200,200), Qt::KeepAspectRatio);
                painter.drawImage(x, y,img);

//                painter.drawText(rect, 0, m_vecMessageFileRecap[i].FileData);//字体居中
            }

            iTempWight += curWight;
        }
    }

    if (iBubbeHeight + 40 != height()){
        resize(width(), iBubbeHeight + 40);
        emit sig_resize(iBubbeHeight + 40);
    }
}

//void ChatBubble::paintEvent(QPaintEvent *e)
//{
//    QFont font("", 16, QFont::Bold, true);

//    // 获取文字的长度
//    QString sNewText;
//    QString sTempText;
//    int iTextLen = width() - 33;

//    int iHeight = 20;
//    bool bHanzi = false;

//    for (int i = 0; i < m_sBubbleText.size(); i++)
//    {
//        if (m_sBubbleText[i] > 128 || m_sBubbleText[i] < 0){
//            bHanzi = true;
//        }

//        if (QFontMetrics(font).width(sTempText + m_sBubbleText[i]) >= iTextLen)
//        {
//            sNewText += "\n";
//            if (bHanzi) {
//                iHeight += QFontMetrics(font).height() + 5;
//            }else{
//                iHeight += QFontMetrics(font).height() - 2;
//            }
//            sTempText = "";
//            bHanzi = false;
//        }
//        sNewText += m_sBubbleText[i];
//        sTempText += m_sBubbleText[i];
//    }

//    if (iHeight + 40 != height())
//    {
////        resize(iBoxLen + 20, iHeight + 40);
//        qDebug() << "height:" << iHeight + 40;
//        emit sig_resize(iHeight + 40);
//    }

//    QRectF rectangle(10, 10, width() - 20, iHeight + 20);

//    QPainter painter(this);
//    painter.setRenderHint( QPainter::Antialiasing, true );
//    QPen pen;
//    pen.setColor(QColor(173,216,67));
//    painter.setPen(pen);

//    painter.setBrush(QBrush(QColor(173,216,67)));
//    painter.drawRoundedRect(rectangle,10,10);

//    if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleLeft) {
//        QPointF points[3] = {
//           QPointF(0, 33),
//           QPointF(11, 28),
//           QPointF(11, 38),
//       };
//       painter.drawPolygon(points, 3);
//    }
//    else if (m_bubbleOrient == ENUM_BubbleOrient::ENUM_BubbleRight) {
//        QPointF points_2[3] = {
//           QPointF(this->width(), 33),
//           QPointF(this->width()-11, 28),
//           QPointF(this->width()-11, 38),
//       };
//       painter.drawPolygon(points_2, 3);
//    }

//    // 绘制文字
//    painter.setPen(QColor(Qt::black));
//    painter.setFont(font);


//    QRectF rect(20, 16, width(), height());
//    painter.drawText(rect, 0, sNewText);//字体居中

////    if (iHeight + 40 != height()){
////        resize(width(), iHeight + 40);
////    }
//}
