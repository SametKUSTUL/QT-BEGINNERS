#include "child.h"

Child::Child(QObject *parent) : QObject(parent)
{
    qInfo()<<this<<"Child constructored!";
}

Child::~Child()
{
    qInfo()<<this<<"Child deconstructored!";
}
