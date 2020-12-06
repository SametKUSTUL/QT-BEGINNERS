#include "test.h"

test::test()
{
    qInfo()<< "Constructed"<<this;
}

test::~test()
{
    qInfo()<< "Deconstructed"<<this;
}
