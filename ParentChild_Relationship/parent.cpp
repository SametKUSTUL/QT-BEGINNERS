#include "parent.h"

parent::parent(QObject *parent) : QObject(parent)
{
    qInfo()<<this<<"Parent constructored!";

}

parent::~parent()
{
    qInfo()<<this<<"Parent deconstructored!";
}
