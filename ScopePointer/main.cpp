#include <QCoreApplication>
#include "test.h"
#include "deneme.h"
#include <QDebug>

void useIt(test* obj){
    if(!obj) return;
    qInfo()<< "Using"<<obj;
}

void doStuff(){
    QScopedPointer<test> myPointer(new test());
    useIt(myPointer.data());

    // pointer is automatically deleted!!
}
void testEt(){
    test *tes=new test();
    delete tes;
}

void ScopeTestEt(){
    QScopedPointer<deneme>myDeneme(new deneme);
    myDeneme.data()->setObjectName("Deneem 2");
}

void ScopeParameter(QScopedPointer<test> &scopePoint){

    qInfo()<<scopePoint.data()->name;
    delete scopePoint.data();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    for(int i=0;i<10;i++){
        doStuff();
    }
    qInfo()<<"*************";
    testEt();
    qInfo()<<"*************";

    deneme *dd=new deneme();
    dd->setObjectName("Deneme 1");
    delete dd;

    ScopeTestEt();

    QScopedPointer <test> myScope(new test);
    myScope.data()->name="MyScope";

    ScopeParameter(myScope);


    return a.exec();
}
