#include "mytcpserver.h"

#include <QNetworkInterface>
#include <QDebug>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    if (!server->listen(QHostAddress::Any,1234)){
        qCritical() << "Unable to start Server" << server->errorString();
    }else{
        qInfo() << "Server listening on: ";

        QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();
        for(int i=0; i < ipAddressList.length(); i++)        {
            if (ipAddressList.at(i).toIPv4Address()){
                qInfo() << ipAddressList.at(i).toString();
            }
        }

        qInfo() << "Port" << server->serverPort();
        connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    }
}

void MyTcpServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    qInfo() << "Client connected on: " << socket->localAddress().toString();
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void MyTcpServer::disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Client disconnected";
    socket->deleteLater();
}

void MyTcpServer::readyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    QByteArray answer = "You ask, I answer\r\n";
    qInfo() << "Client data ready" << data;
    write(socket, answer);
}

void MyTcpServer::write(QTcpSocket *socket, QByteArray data)
{
    qInfo() << "Send to client: " << data;
    socket->write(data);
    socket->flush();
}
