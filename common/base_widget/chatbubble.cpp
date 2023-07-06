#include "chatbubble.h"
#include <QPainter>
#include <QLabel>
#include <QFontMetrics>
#include <QDebug>
#include <QPushButton>

ChatBubble::ChatBubble(QWidget *parent, ENUM_BubbleOrient orient, QVector<MessageFileRecap> vecMessageFileRecap) : QWidget(parent)
{
    m_iMaxWidth = 360;
    m_iMinWidth = 220;
//    this->setMinimumSize(m_iMinWidth, 60);
//    this->setMaximumSize(m_iMaxWidth, 6000);
    m_bubbleOrient = orient;
    m_vecMessageFileRecap = vecMessageFileRecap;

    pBtnDownLoad = new QPushButton(tr("下载"), this);
    pBtnDownLoad->setStyleSheet("background-color:white;color:blue;border:0px solid white;");
    pBtnOpen = new QPushButton(tr("打开"), this);
    pBtnOpen->setStyleSheet("background-color:white;color:blue;border:0px solid white;");
    pBtnOpenPath = new QPushButton(tr("打开路径"),this);
    pBtnOpenPath->setStyleSheet("background-color:white;color:blue;border:0px solid white;");

    pBtnDownLoad->setHidden(true);
    pBtnOpen->setHidden(true);
    pBtnOpenPath->setHidden(true);

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

QString ChatBubble::ChooseFileIcon(QString path)
{
    QString strFileExtension = "";

    for(int j = path.size() - 1; j >= 0; j--)
    {
        if (path[j] == ".")
        {
            strFileExtension = path.mid(j + 1);
            break;
        }
    }

    if (strFileExtension == "txt")
    {
        return ":/img/im_chat_file_txt.png";
    }
    if(strFileExtension == "css")
    {
        return ":/img/im_chat_file_css.png";
    }
    if(strFileExtension == "html")
    {
        return ":/img/im_chat_file_html.png";
    }
    if(strFileExtension == "mp3")
    {
        return ":/img/im_chat_file_mp3.png";
    }
    if(strFileExtension == "mp4")
    {
        return ":/img/im_chat_file_mp4.png";
    }
    if(strFileExtension == "pdf")
    {
        return ":/img/im_chat_file_pdf.png";
    }
    if(strFileExtension == "zip")
    {
        return ":/img/im_chat_file_zip.png";
    }

    return ":/img/im_chat_file_defalut.png";
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
            curHeight = 100;
            curWight = 200;
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
            curHeight = 100;
            curWight = 200;
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

            if (m_vecMessageFileRecap[i].MessageFileType == 3) {
                // 文件预览框
                QPainter painter_file(this);
                painter_file.setRenderHint( QPainter::Antialiasing, true );
                QPen pen_file;
                pen_file.setColor(QColor(255,255,255));
                painter_file.setPen(pen_file);

                painter_file.setBrush(QBrush(QColor(255,255,255)));
                QRectF rectangleBubble(x, y, curWight, curHeight);
                painter_file.drawRoundedRect(rectangleBubble,15,15);

                QFont font_file("", 13, QFont::Normal, true);
                painter_file.setPen(QColor(Qt::gray));
                painter_file.setFont(font_file);

                // 文件缩略图
                QImage img(ChooseFileIcon(m_vecMessageFileRecap[i].FileName));

                img = img.scaled(QSize(50,50), Qt::KeepAspectRatio);
                painter_file.drawImage(x + 10, y + 10,img);

                QString name = m_vecMessageFileRecap[i].FileName;
                for (int j = m_vecMessageFileRecap[i].FileName.size() - 1; j >= 0; j--)
                {
                    if (m_vecMessageFileRecap[i].FileName[j] == tr("/") && j != m_vecMessageFileRecap[i].FileName.size() - 1)
                    {
                        name = m_vecMessageFileRecap[i].FileName.mid(j + 1);
                        break;
                    }
                }

                painter_file.drawText(QRectF(x + 70, y + 10, 100, 20), 0, name);//字体居中
                painter_file.drawText(QRectF(x + 70, y + 40, 100, 20), 0, QString::number(m_vecMessageFileRecap[i].FileSize) + "B");//字体居中

                QFont font_Link("", 12, QFont::Bold, true);
                painter_file.setPen(QColor(Qt::blue));
                painter_file.setFont(font_Link);

//                painter_file.drawText(QRectF(x + 30, y + 70, 100, 20), 0, tr("下载")); // 下载
//                painter_file.drawText(QRectF(x + 70, y + 70, 100, 20), 0, tr("打开")); // 打开
//                painter_file.drawText(QRectF(x + 110, y + 70, 100, 20), 0, tr("打开路径")); // 打开路径

                pBtnDownLoad->setGeometry(x + 30, y + 70, 40, 20);
                pBtnOpen->setGeometry(x + 70, y + 70, 40, 20);
                pBtnOpenPath->setGeometry(x + 110, y + 70, 60, 20);

                pBtnDownLoad->setHidden(false);
                pBtnOpen->setHidden(false);
                pBtnOpenPath->setHidden(false);
            }

            iTempWight += curWight;
        }
    }

    if (iBubbeHeight + 40 != height()){
        resize(width(), iBubbeHeight + 40);
        emit sig_resize(iBubbeHeight + 40);
    }
}
