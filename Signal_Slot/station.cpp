#include "station.h"

station::station(QObject *parent, int channel, QString name) : QObject(parent)
{
    this->channel = channel;
    this->name = name;
    qInfo()<<this<<"-"<<this->name<<"-"<<this->channel<<"	constructored";
}

void station::broadcast(QString message)
{
    emit send(channel,name, message);
}
