#ifndef FIEND_H
#define FIEND_H

#include <QString>
#include <QList>

class Fiend
{
public:
    Fiend(const QString& name);
    ~Fiend();

    void getName(QString& name);
    int getCaptureCount() const;
    void setCaptureCount(int captureCount);

private:
    QString name_;
    QList<QString> areas_;
    unsigned int captureCount_;
};

#endif
