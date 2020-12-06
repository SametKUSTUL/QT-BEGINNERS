#include <QCoreApplication>
#include "test.h"
#include "watcher.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test tester;
    watcher destination;

    QObject::connect(&tester,&test::messageChanged,&destination,&watcher::messageChanged);
    QObject::connect(&tester,&test::changeInt,&destination,&watcher::changeIntWa);
    tester.setProperty("message","DENEME");
    tester.setProperty("ddd",55);
   // tester.setMessage("testing");
    return a.exec();
}
