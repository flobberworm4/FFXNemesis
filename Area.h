#ifndef AREA_H
#define AREA_H

#include <QList>

class Fiend;

class Area
{
public:
    Area(const QString& name, const QStringList& fiendStrings);
    ~Area();

    QList<Fiend*> getFiends() const;
    QString getName() const;

private:
    QString name_;
    QList<Fiend*> fiends_;
};

#endif
