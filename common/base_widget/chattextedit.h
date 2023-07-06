#ifndef CHATTEXTEDIT_H
#define CHATTEXTEDIT_H

/*
    ****** 编辑框只接收文字和图片 ******
*/

#include <QWidget>
#include <QTextEdit>
#include <QFileInfo>
#include <QMimeData>
#include <QImageReader>
#include <QImage>
#include <QTextTable>
#include <QByteArray>
#include "../commonproto/home_chat.pb.h"

struct InputMessage {
    QVector<im_home_proto::MessageFileRecap> fileInfos;
    QString messageText;
};

class ChatTextEdit : public QTextEdit
{

public:
    ChatTextEdit(QWidget *parent = nullptr);
    InputMessage GetInputMessage();
    bool canInsertFromMimeData(const QMimeData* source) const;
    void insertFromMimeData(const QMimeData* source);

private:
    void dropImage(const QUrl& url, const QImage& image)
    {
        if (!image.isNull())
        {
            QImage img = image.scaled(QSize(200,200), Qt::KeepAspectRatio);

            document()->addResource(QTextDocument::ImageResource, url, img);
            textCursor().insertImage(url.toString());
        }
    }

//    void dropTextFile(const QUrl& url)
//    {
//        QFile file(url.toLocalFile());
//        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//            textCursor().insertImage(url.toString());
//    }
};

#endif // CHATTEXTEDIT_H
