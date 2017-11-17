#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();
    void disconnected();
    void readyRead();

private:
    QTcpServer *server;
};

#endif // MYTCPSERVER_H
