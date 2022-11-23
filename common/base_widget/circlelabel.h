#ifndef CIRCLELABEL_H
#define CIRCLELABEL_H
/*
    圆形的label,可用做头像
*/

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QObject>
// 样式
enum ENUM_CircleStyle {
    ENUM_Solid = 0,         // (图片,纯色) 实心圆
    ENUM_Head = 1,          // (图片,纯色) 外面带了一圈悬浮边框的实心圆(特殊用于头像显示)
    ENUM_SolidNumber = 2    // (纯色,文字) 实心圆里面显示数字
};

class CircleLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CircleLabel(QWidget* parent = nullptr, ENUM_CircleStyle style = ENUM_Solid);
    void SetImgPath(QString path);
    void SetCircleColor(Qt::GlobalColor color);   // 设置圆圈颜色(可以表示在线,离线状态)
    void SetFontColor(Qt::GlobalColor color);     // 设置字体颜色
    void SetCircleLabelText(QString sText);       // 设置字体文本
    void SetCircleLabelHide(bool bHide);          // 设置隐藏(把控件画空白)

signals:
    void sig_clicked();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

private:
    bool m_set;//透明度的
    QString m_sImgPath;
    ENUM_CircleStyle m_style;
    Qt::GlobalColor m_circleColor;
    Qt::GlobalColor m_fontColor;
    QString m_sText;
    bool m_bHide;
};

#endif // CIRCLELABEL_H
