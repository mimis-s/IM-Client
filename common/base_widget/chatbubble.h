#ifndef CHATBUBBLE_H
#define CHATBUBBLE_H

#include <QWidget>
#include <QFont>
#include "../commonproto/home_chat.pb.h"
// 气泡朝向(朝左则开口在左上角, 朝右则开口在右上角)
enum ENUM_BubbleOrient {
    ENUM_BubbleLeft = 0,
    ENUM_BubbleRight = 1,
};

struct MessageFileRecap {
    QString FileName;
    QString FileExtension; // 文件扩展名
    int64_t FileSize;       // 文件大小
    int FileIndex;

    QString FileLocalPath;
    QString FileData;           // 图片或者文件内容
    im_home_proto::MessageFileType_Enum MessageFileType;        // 文件类型(1:文本; 2:图片; 3:文件)
};

class ChatBubble : public QWidget
{
    Q_OBJECT
public:
    explicit ChatBubble(QWidget *parent = nullptr, ENUM_BubbleOrient orient = ENUM_BubbleOrient::ENUM_BubbleRight, QVector<MessageFileRecap> vecMessageFileRecap = {});

    void SetBubbleOrient(ENUM_BubbleOrient orient);
    int GetMaxWidth();
    int GetMinWidth();

signals:
    void sig_resize(int iHeight);
protected:
    void paintEvent(QPaintEvent *e);

private:
    ENUM_BubbleOrient m_bubbleOrient;
    QVector<MessageFileRecap> m_vecMessageFileRecap;

    int m_iMaxWidth;
    int m_iMinWidth;
};

#endif // CHATBUBBLE_H
