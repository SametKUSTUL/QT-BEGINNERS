#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
    QString n_message;
    int denemeSayisi;
public:
    explicit test(QObject *parent = nullptr);

    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(int ddd READ ddd WRITE setInt NOTIFY changeInt)
    QString message();
    int ddd();
    void setMessage(QString value);
    void setInt(int value);
signals:
    void messageChanged(QString message);
    void changeInt(int value);

public slots:
};

#endif // TEST_H
