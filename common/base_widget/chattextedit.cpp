#include "chattextedit.h"

ChatTextEdit::ChatTextEdit(QWidget *parent) : QTextEdit(parent)
{
}

InputMessage ChatTextEdit::GetInputMessage() {
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
                     im_home_proto::MessageFileRecap messageFileRecap;
                     messageFileRecap.set_filename(imgName.toStdString());
                     messageFileRecap.set_filesize(image.byteCount());
                     messageFileRecap.set_fileindex(i.fragment().position());
                     messageFileRecap.set_messagefiletype(im_home_proto::EnumImgType);
//                         QByteArray arr = QByteArray::fromRawData((const char*)image.bits(), image.byteCount());

                     QByteArray imgByte;
                     QDataStream ds(&imgByte, QIODevice::WriteOnly);
                     ds<<image;
                     QString str = QString::fromLocal8Bit(imgByte.toBase64());

                     messageFileRecap.set_filedata(str.toStdString().c_str());
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

bool ChatTextEdit::canInsertFromMimeData(const QMimeData* source) const
{
    return source->hasImage() || QTextEdit::canInsertFromMimeData(source);
}

void ChatTextEdit::insertFromMimeData(const QMimeData* source)
{
    if (source->hasImage())
    {
        static int i = 1;
        QUrl url(QString("dropped_image_%1").arg(i++));
        dropImage(url, qvariant_cast<QImage>(source->imageData()));
    }
//    else if (source->hasUrls())
//    {
//        foreach (QUrl url, source->urls())
//        {
//            QFileInfo info(url.toLocalFile());
//            if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
//                dropImage(url, QImage(info.filePath()));
//            else
//            {
//                QFile file(url.toLocalFile());
//                InputMessage inputMsg;
//                im_home_proto::MessageFileRecap messageFileRecap;
//                messageFileRecap.set_filename(file.fileName().toStdString());
//                messageFileRecap.set_filesize(file.size());
//                messageFileRecap.set_fileindex(0);
//                messageFileRecap.set_messagefiletype(im_home_proto::EnumFileType);

////                    QByteArray fileByte;
////                    QDataStream ds(&fileByte, QIODevice::WriteOnly);
////                    ds<<file.readAll();
////                    QString str = QString::fromLocal8Bit(fileByte.toBase64());

////                    messageFileRecap.set_filedata(str.toStdString().c_str());
//                inputMsg.fileInfos.append(messageFileRecap);
////                emit sigSendFile();
////                    dropTextFile(url);
//            }
//        }
//    }
    else
    {
        QTextEdit::insertFromMimeData(source);
    }
}

