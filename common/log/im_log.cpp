#include "im_log.h"
#include <QDateTime>
#include <QDebug>

IMLog *IMLog::m_pLog = nullptr;

IMLog::IMLog()
{
}

IMLog::~IMLog()
{
}

void IMLog::Info(QString log)
{
    qDebug() << "Info"
             << " " << QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss") << " " << log;
}

void IMLog::Warn(QString log)
{
    qDebug() << "Info"
             << " " << QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss") << " " << log;
}

void IMLog::Error(QString log)
{
    qDebug() << "Error"
             << " " << QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss") << " " << log;
}