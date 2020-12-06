#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

QString test::message()
{
    return n_message;
}

int test::ddd()
{
    return denemeSayisi;
}

void test::setMessage(QString value)
{
    n_message=value;
    emit messageChanged(n_message);
}

void test::setInt(int value)
{
    denemeSayisi=value;
    emit changeInt(denemeSayisi);
}
