#ifndef CHATTEXTEDIT_H
#define CHATTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QFileInfo>
#include <QMimeData>
#include <QImageReader>
#include <QImage>
#include <QTextTable>
#include <QByteArray>
#include "../commonproto/home_chat.pb.h"
//class ChatTextEdit : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit ChatTextEdit(QWidget *parent = nullptr);

//signals:

//};

struct InputMessage {
    QVector<im_home_proto::MessageFileRecap> fileInfos;
    QString messageText;
};



class ChatTextEdit : public QTextEdit
{
public:
    explicit ChatTextEdit(QWidget *parent = nullptr);

    InputMessage GetInputMessage() {
        InputMessage inputMsg;

        QTextDocument *document = this->document();
        QTextBlock block = document->begin();
        while (block.isValid())
        {
            for (QTextBlock::iterator i = block.begin(); !i.atEnd(); ++i)
            {
                 QTextCharFormat format = i.fragment().charFormat();
                 bool isImage = format.isImageFormat();
                 if (isImage)
                 {
                     QTextImageFormat imgf = format.toImageFormat();
                     if(document->resource(QTextDocument::ImageResource, imgf.name()).canConvert<QPixmap>())
                     {
                         QString type = document->resource(QTextDocument::ImageResource, imgf.name()).typeName();
                         QVariant var = document->resource(QTextDocument::ImageResource, imgf.name());
                         QString imgName = imgf.name();
                        //取出图片
                         QImage image = QImage(var.value<QImage>());
                         QPixmap map = QPixmap().fromImage(image);
                         im_home_proto::MessageFileRecap messageFileRecap;
                         messageFileRecap.set_filename(imgName.toStdString());
                         messageFileRecap.set_filesize(image.byteCount());
                         messageFileRecap.set_fileindex(i.fragment().position());
                         messageFileRecap.set_messagefiletype(im_home_proto::EnumImgType);
                         QByteArray arr = QByteArray::fromRawData((const char*)image.bits(), image.byteCount());
                         messageFileRecap.set_filedata(arr.toStdString());
                         inputMsg.fileInfos.append(messageFileRecap);
                     }
                 }else{
                     inputMsg.messageText += i.fragment().text();
                 }
            }
            block = block.next();
        }

        return inputMsg;
    };

    bool canInsertFromMimeData(const QMimeData* source) const
    {
        return source->hasImage() || source->hasUrls() ||
            QTextEdit::canInsertFromMimeData(source);
    }

    void insertFromMimeData(const QMimeData* source)
    {
        if (source->hasImage())
        {
            static int i = 1;
            QUrl url(QString("dropped_image_%1").arg(i++));
            dropImage(url, qvariant_cast<QImage>(source->imageData()));
        }
        else if (source->hasUrls())
        {
            foreach (QUrl url, source->urls())
            {
                QFileInfo info(url.toLocalFile());
                if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
                    dropImage(url, QImage(info.filePath()));
//                else
//                    dropTextFile(url);
            }
        }
        else
        {
            QTextEdit::insertFromMimeData(source);
        }
    }

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
//            textCursor().insertText(file.readAll());
//    }
};

#endif // CHATTEXTEDIT_H
