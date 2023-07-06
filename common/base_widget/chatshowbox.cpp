#include "chatshowbox.h"
#include <QMimeData>
#include <QImageReader>
#include <QFileInfo>

ChatShowBox::ChatShowBox(QWidget *parent) : QListWidget(parent)
{
    this->setAcceptDrops(true);
}

void ChatShowBox::dragEnterEvent(QDragEnterEvent *event)
{
//    QListWidget* source  = qobject_cast<QListWidget*>(event->source());
//    //判断是否位空,判断自己是为自己
//    if(source!=NULL && (source!=this)){
//        event->setDropAction(Qt::MoveAction);
//        event->accept();
//    }
    if (event->mimeData()->hasUrls() || event->mimeData()->hasImage())
    {
        event->acceptProposedAction();
    }
}

void ChatShowBox::dragMoveEvent(QDragMoveEvent *event)
{
//    QListWidget* source  = qobject_cast<QListWidget*>(event->source());
//    //判断是否位空,判断自己是为自己
//    if(source!=NULL && (source!=this)){
//        event->setDropAction(Qt::MoveAction);
//        event->accept();
//    }
    if (event->mimeData()->hasUrls() || event->mimeData()->hasImage())
    {
        event->acceptProposedAction();
    }
}

void ChatShowBox::dropEvent(QDropEvent *event)
{
    InputMessage inputMsg;

    foreach (QUrl url, event->mimeData()->urls())
    {
        QFileInfo info(url.toLocalFile());
        if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
        {
            //取出图片
            QImage image = QImage(info.filePath());
            im_home_proto::MessageFileRecap messageFileRecap;
            messageFileRecap.set_filename(info.fileName().toStdString());
            messageFileRecap.set_filesize(image.byteCount());
            messageFileRecap.set_fileindex(0);
            messageFileRecap.set_messagefiletype(im_home_proto::EnumImgType);

            inputMsg.fileInfos.append(messageFileRecap);
        }
        else
        {
            QFile file(url.toLocalFile());
            im_home_proto::MessageFileRecap messageFileRecap;
            messageFileRecap.set_filename(file.fileName().toStdString());
            messageFileRecap.set_filesize(file.size());
            messageFileRecap.set_fileindex(0);
            messageFileRecap.set_messagefiletype(im_home_proto::EnumFileType);

            inputMsg.fileInfos.append(messageFileRecap);
        }
    }
    emit sigDropFile(inputMsg);
}
