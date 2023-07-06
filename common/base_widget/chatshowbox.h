#ifndef CHATSHOWBOX_H
#define CHATSHOWBOX_H

#include <QListWidget>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include "chattextedit.h"

class ChatShowBox : public QListWidget
{
    Q_OBJECT
public:
    ChatShowBox(QWidget *parent = nullptr);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

signals:
    void sigDropFile(InputMessage);

};

#endif // CHATSHOWBOX_H
