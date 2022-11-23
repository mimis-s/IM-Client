#include "circlelabel.h"
#include <QPainter>
#include <QtDebug>

CircleLabel::CircleLabel(QWidget* parent, ENUM_CircleStyle style):QLabel (parent)
{
    m_style = style;
    m_color = Qt::green;
}

void CircleLabel::SetImgPath(QString path)
{
    m_sImgPath = path;
}

// 设置颜色可以表示在线,离线状态
void CircleLabel::SetColor(Qt::GlobalColor color)
{
    m_color = color;
}

void CircleLabel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (m_style == ENUM_CircleStyle::ENUM_Solid)
    {
        //设置反锯齿
        painter.setRenderHints(QPainter::Antialiasing |
                               QPainter::SmoothPixmapTransform);
        QPainterPath path;
        int round = qMin(width() - 2, height() - 2);
        path.addEllipse(1, 1, round, round);

        if (m_sImgPath != ""){

            painter.setClipPath(path);
            QPixmap pixMap(m_sImgPath);
            painter.drawPixmap(-1,-1,width()+10,height()+10,pixMap);
        }else{
            painter.setBrush(QBrush(m_color));
            painter.setPen(QPen(m_color,0));
            painter.drawPath(path);
        }
    }
    else if (m_style == ENUM_CircleStyle::ENUM_Head)
    {
        //设置反锯齿
        painter.setRenderHints(QPainter::Antialiasing |
                               QPainter::SmoothPixmapTransform);
        QPainterPath path;
        int round = qMin(width() - 16, height() - 16);
        path.addEllipse(8, 8, round, round);

        if (m_sImgPath != ""){

            painter.setClipPath(path);
            QPixmap pixMap(m_sImgPath);
            painter.drawPixmap(-1,-1,width()+10,height()+10,pixMap);
        }else{
            painter.setBrush(QBrush(m_color));
            painter.setPen(QPen(m_color,0));
            painter.drawPath(path);
        }

        QPainter painter_side(this);

        QPainterPath path_side;
        int round_side = qMin(width() - 4, height() - 4);
        path_side.addEllipse(2, 2, round_side, round_side);

        painter_side.setRenderHints(QPainter::Antialiasing);
        painter_side.setPen(QPen(m_color, 1, Qt::SolidLine, Qt::RoundCap));
        painter_side.drawPath(path_side);

        QPainter painter_point(this);
        painter_point.setRenderHints(QPainter::Antialiasing);
        painter_point.setPen(QPen(m_color, 1));
        painter_point.setBrush(QBrush(m_color));

        int len = width() > height() ? height():width();

        int pointW = len/2 + len/2/2 + 2;
        int pointH = len/2/2/2/2;
        painter_point.drawEllipse(pointW, pointH, 10, 10);
    }
    else {
        QLabel::paintEvent(e);
    }
}

void CircleLabel::mousePressEvent(QMouseEvent *ev)
{
     m_set = true;
     update();
     QLabel::mousePressEvent(ev);
}

void CircleLabel::mouseMoveEvent(QMouseEvent *ev)
{
    m_set = false;
    update();
    QLabel::mouseMoveEvent(ev);
}

void CircleLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    m_set = false;
    update();
    emit sig_clicked();
    QLabel::mouseReleaseEvent(ev);
}
