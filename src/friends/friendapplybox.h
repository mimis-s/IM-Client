#ifndef FRIENDAPPLYBOX_H
#define FRIENDAPPLYBOX_H

#include <QWidget>
#include "../../common/base_widget/chatshortframe.h"
#include <QPushButton>
#include <QLabel>

namespace Ui {
class FriendApplyBox;
}

class FriendApplyBox : public QWidget
{
    Q_OBJECT

public:
    explicit FriendApplyBox(QWidget *parent = nullptr, ChatShortFrameData data = ChatShortFrameData{}, bool bSend = true);
    ~FriendApplyBox();

public slots:
    void slot_agreeFriendApplyClick();  // 同意好友申请
    void slot_ignoreFriendApplyClick(); // 忽略好友申请

private:
    Ui::FriendApplyBox *ui;
    ChatShortFrame *m_pChatShortFrame;
    QPushButton *m_pBtnAgree;   // 同意
    QPushButton *m_pBtnIgnore;  // 忽略
    QLabel *m_pLbAlreadySend;   // 已发送好友申请

    ChatShortFrameData m_applyFriendData;

};

#endif // FRIENDAPPLYBOX_H
