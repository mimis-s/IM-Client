#ifndef CUTOUTHEAD_H
#define CUTOUTHEAD_H

/*
    截取头像界面
*/

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QImage>
#include <QLabel>

// 裁剪框

class CutOutBox : public QLabel
{
    Q_OBJECT

public:
    explicit CutOutBox(QWidget *parent = nullptr);
    ~CutOutBox();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void sig_pressAndMove(int iX,int iY);    // 按住并拖动

private:
    bool m_bPress; // 鼠标是否按住

    int m_mouseX;   // 按下的时候所在的X坐标
    int m_mouseY;   // 按下的时候所在的Y坐标
};

namespace Ui {
class CutOutHead;
}

class CutOutHead : public QDialog
{
    Q_OBJECT

public:
    explicit CutOutHead(QWidget *parent = nullptr, QImage imag = QImage());
    ~CutOutHead();

public slots:
    void slot_pressAndMove(int iX,int iY);    // 按住剪切框并拖动
    void slot_btnCutClicked();
    void slot_btnCancelClicked();

signals:
    void sig_cutImag(QImage imag); // 成功剪切图片

private:
    Ui::CutOutHead *ui;

    CutOutBox *m_pCutOutBox; // 剪切框
    QWidget *m_pImgShowBox;  // 图片展示框

    QImage m_imag;
};

#endif // CUTOUTHEAD_H
