#ifndef IM_CLIENT_H
#define IM_CLIENT_H

#include <QWidget>
#include "common/base_widget/friendchatbox.h"

namespace Ui
{
    class IMClient;
}

class IMClient : public QWidget
{
    Q_OBJECT

public:
    explicit IMClient(QWidget *parent = 0);
    ~IMClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IMClient *ui;

    FriendChatBox *pbox;
};

#endif // IM_CLIENT_H
