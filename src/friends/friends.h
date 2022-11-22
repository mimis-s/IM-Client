#ifndef FRIENDS_H
#define FRIENDS_H

#include <QWidget>

namespace Ui {
class friends;
}

class friends : public QWidget
{
    Q_OBJECT

public:
    explicit friends(QWidget *parent = nullptr);
    ~friends();

private:
    Ui::friends *ui;
};

#endif // FRIENDS_H
