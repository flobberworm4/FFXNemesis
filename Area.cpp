#include "Area.h"

#include "Fiend.h"

Area::Area(const QString& name, const QStringList& fiendStrings)
: name_(name)
, fiends_()
{
    foreach (const QString& fiendString, fiendStrings)
    {
        Fiend* fiend = new Fiend(fiendString);
        fiends_.push_back(fiend);
    }
}



Area::~Area()
{
}



QList<Fiend*> Area::getFiends() const
{
    return fiends_;
}



QString Area::getName() const
{
    return name_;
}
