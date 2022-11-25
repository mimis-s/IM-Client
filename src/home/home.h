#ifndef HOME_H
#define HOME_H

/*
    chat
    friend
    group
*/

#include <QWidget>
#include "../chat/chat.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;

    Chat *m_pChat;
};

#endif // HOME_H
