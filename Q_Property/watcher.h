#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>

class watcher : public QObject
{
    Q_OBJECT
public:
    explicit watcher(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WATCHER_H