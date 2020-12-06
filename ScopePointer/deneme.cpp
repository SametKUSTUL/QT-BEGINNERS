#include "deneme.h"
#include <QDebug>
deneme::deneme(QObject *parent) : QObject(parent)
{
    qInfo()<< this->objectName()<<"  Constructed"<<this;
}

deneme::~deneme()
{
    qInfo()<< this->objectName()<<" Deconstructed"<<this;

}
