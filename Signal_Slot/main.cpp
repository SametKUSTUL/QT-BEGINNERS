#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    radio boombox;
    station* channels[3];

    //create some stations
    channels[0] = new station(&boombox,94,"Rock and roll");
    channels[1] = new station(&boombox,101,"Hip hop");
    channels[2] = new station(&boombox,85,"News");

    //Qt::QueuedConnection = used when you work with threads
    boombox.connect(&boombox,&radio::quit,&a,&QCoreApplication::quit, Qt::QueuedConnection);

    do {
        qInfo() << "Enter on, off, test or quit:";
        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toUpper();


        if(line == "ON") {
            qInfo() << "Turing the radio on";
            for(int i = 0; i < 3; i++) {
                station* channel = channels[i];
                boombox.connect(channel, &station::send,&boombox, &radio::listen);
            }
            qInfo() << "Radio is on!";
        }

        if(line == "OFF") {
            qInfo() << "Turing the radio off";
            for(int i = 0; i < 3; i++) {
                station* channel = channels[i];
                //QObject::connect(channel,SIGNAL(send(int,QString,QString)),&boombox,SLOT(listen(int,QString,QString)));
                boombox.disconnect(channel, &station::send,&boombox, &radio::listen);
            }
            qInfo() << "Radio is off!";
        }

        if(line == "TEST") {
            qInfo() << "Testing";
            for(int i = 0; i < 3; i++) {
                station* channel = channels[i];
                channel->broadcast("Broadcasting live!");
            }
            qInfo() << "Testing complete";
        }

        if(line == "QUIT") {
            qInfo() << "Quitting";
            emit boombox.quit();
            break;
        }

    } while(true);

    return a.exec();
}
