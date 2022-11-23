#ifndef CIRCLELABEL_H
#define CIRCLELABEL_H
/*
    圆形的label,可用做头像
*/

#include <QWidget>
#include <QLabel>
#include <QPixmap>

// 样式
enum ENUM_CircleStyle {
    ENUM_Solid = 0, // 实心圆
    ENUM_Head = 1   // 外面带了一圈悬浮边框的实心圆(特殊用于头像显示)
};

class CircleLabel : public QLabel
{
    Q_OBJECT
public:
    CircleLabel(QWidget* parent = nullptr, ENUM_CircleStyle style = ENUM_Solid);
    void SetImgPath(QString path);
    void SetColor(Qt::GlobalColor color);   // 设置颜色可以表示在线,离线状态

signals:
    void sig_clicked();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

private:
    bool m_set;//透明度的
    QPixmap m_oldMap;
    QString m_sImgPath;
    ENUM_CircleStyle m_style;
    Qt::GlobalColor m_color;
};

#endif // CIRCLELABEL_H
