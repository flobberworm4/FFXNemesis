#include "Fiend.h"

Fiend::Fiend(const QString& name)
: name_(name)
, captureCount_(0)
{

}



Fiend::~Fiend()
{

}



void Fiend::getName(QString& name)
{
    name = name_;
}



int Fiend::getCaptureCount() const
{
    return captureCount_;
}



void Fiend::setCaptureCount(int captureCount)
{
    captureCount_ = captureCount;
}
