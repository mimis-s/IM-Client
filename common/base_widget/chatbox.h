#ifndef CHATBOX_H
#define CHATBOX_H

/*
    带有发送按钮,输入框, 聊天展示框等功能的聊天框
*/

#include <QWidget>
#include "circlelabel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QListWidgetItem>

class ChatBox : public QWidget
{
    Q_OBJECT
public:
    explicit ChatBox(QWidget *parent = nullptr);
    void AddMessage(bool bSelf, QString sMessage, QString sHeadPath);
signals:

public slots:
    void slot_btnSendClick();

private:

    CircleLabel *m_pLbHead;
    QLabel *m_pLbName;
    QPushButton *m_pBtnPhone;
    QPushButton *m_pBtnVideo;
    QListWidget *m_pMiddleListWidget;
    QPushButton *m_pBtnEmoj;
    QTextEdit *m_pTextInput;
    QPushButton *m_pBtnSend;
};

#endif // CHATBOX_H
