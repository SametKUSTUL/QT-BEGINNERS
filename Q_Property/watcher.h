#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>
class watcher : public QObject
{
    Q_OBJECT
public:
    explicit watcher(QObject *parent = nullptr);

signals:

public slots:
    void messageChanged(QString message);
    void changeIntWa(int i);
};

#endif // WATCHER_H
