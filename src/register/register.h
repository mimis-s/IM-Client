#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QDialog>

namespace Ui
{
    class CUserRegister;
}

class CUserRegister : public QDialog
{
    Q_OBJECT

public:
    explicit CUserRegister(QDialog *parent = 0);
    ~CUserRegister();
    void RegisterBack(char * recvMessage);

public slots:
    void slot_btn_register();

private slots:
    void on_btn_register_head_clicked();
    void slot_cutHead(QImage);

private:
    Ui::CUserRegister *ui;

    QImage m_imageHead;
};

#endif // REGISTER_H
