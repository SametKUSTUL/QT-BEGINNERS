#include "radio.h"

radio::radio(QObject *parent) : QObject(parent)
{

}

void radio::listen(int channel, QString name, QString message)
{
    qInfo() <<"Listening:"<< channel << " " << name << " - " << message;
}
