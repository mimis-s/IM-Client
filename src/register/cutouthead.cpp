#include "cutouthead.h"
#include "ui_cutouthead.h"
#include <QMouseEvent>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

// 裁剪框
CutOutBox::CutOutBox(QWidget *parent) :
    QLabel(parent)
{

}

CutOutBox::~CutOutBox()
{

}

void CutOutBox::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPress) {
        int mouseMoveX = event->globalPos().x() - m_mouseX;
        int mouseMoveY = event->globalPos().y() - m_mouseY;
        emit sig_pressAndMove(mouseMoveX, mouseMoveY);    // 按住并拖动
        m_mouseX = event->globalPos().x();
        m_mouseY = event->globalPos().y();
    }
}


void CutOutBox::mousePressEvent(QMouseEvent *event)
{
    m_bPress = true;
    m_mouseX = event->globalPos().x();
    m_mouseY = event->globalPos().y();
}

void CutOutBox::mouseReleaseEvent(QMouseEvent *event)
{
    m_bPress = false;
    m_mouseX = 0;
    m_mouseY = 0;
}

// 裁剪主界面
CutOutHead::CutOutHead(QWidget *parent, QImage imag) :
    QDialog(parent),
    ui(new Ui::CutOutHead)
{
    ui->setupUi(this);

    QVBoxLayout *pMainLayout = new QVBoxLayout(this);

    // 图片展示框
    m_pImgShowBox = new QWidget(this);

    m_pImgShowBox->setAutoFillBackground(true);    // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = m_pImgShowBox->palette();
    palette.setBrush(QPalette::Window,
            QBrush(imag.scaled(    // 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
    m_pImgShowBox->setPalette(palette);

    pMainLayout->addWidget(m_pImgShowBox);

    m_imag = imag.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // 剪切框
    m_pCutOutBox = new CutOutBox(m_pImgShowBox);
    m_pCutOutBox->setStyleSheet("background:rgba(255,255,255,70);border: 1px solid black;");
    m_pCutOutBox->setGeometry(0, 0, 100, 100);

    // 剪切按钮
    QPushButton *pBtnCut = new QPushButton(tr(u8"剪切"), this);
    QPushButton *pBtnCancel = new QPushButton(tr(u8"取消"), this);
    QHBoxLayout *pBtnLayout = new QHBoxLayout();
    pBtnLayout->addStretch();
    pBtnLayout->addWidget(pBtnCut);
    pBtnLayout->addWidget(pBtnCancel);

    pMainLayout->addLayout(pBtnLayout);

    connect(m_pCutOutBox, SIGNAL(sig_pressAndMove(int,int)), this, SLOT(slot_pressAndMove(int,int)));
    connect(pBtnCut, SIGNAL(clicked()), this, SLOT(slot_btnCutClicked()));
    connect(pBtnCancel, SIGNAL(clicked()), this, SLOT(slot_btnCancelClicked()));

    setFixedSize(this->size());
    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint);
}

CutOutHead::~CutOutHead()
{
    delete ui;
}

void CutOutHead::slot_pressAndMove(int iMoveX, int iMoveY)
{
    int newX = m_pCutOutBox->x();
    int newY = m_pCutOutBox->y();

    bool bXMin = m_pCutOutBox->x() + iMoveX > 0;
    bool bXMax = m_pCutOutBox->x() + iMoveX + m_pCutOutBox->width() < m_pImgShowBox->width();
    if (bXMin && bXMax) {
        newX = m_pCutOutBox->x() + iMoveX;
    }

    bool bYMin = m_pCutOutBox->y() + iMoveY > 0;
    bool bYMax = m_pCutOutBox->y() + iMoveY + m_pCutOutBox->height() < m_pImgShowBox->height();
    if (bYMin && bYMax) {
        newY = m_pCutOutBox->y() + iMoveY;
    }

    m_pCutOutBox->move(newX, newY);
}

void CutOutHead::slot_btnCutClicked()
{
    QImage imag = m_imag.copy(m_pCutOutBox->x(), m_pCutOutBox->y(),
                              m_pCutOutBox->width(), m_pCutOutBox->height());
    emit sig_cutImag(imag); // 成功剪切图片
    this->close();
}

void CutOutHead::slot_btnCancelClicked()
{
    this->close();
}













