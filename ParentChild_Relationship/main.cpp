#include <QCoreApplication>
#include <QDebug>
#include "parent.h"
#include "child.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    parent *p = new parent(&a);
    p->child1 = new Child(p);
    delete p; // OPPSS! You don't forget delete !!.
    return a.exec();
}
