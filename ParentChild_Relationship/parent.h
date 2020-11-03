#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include "child.h"
class parent : public QObject
{
    Q_OBJECT
public:
    explicit parent(QObject *parent = nullptr);
    ~parent();

    Child *child1;

signals:

public slots:
};

#endif // TEST_H
