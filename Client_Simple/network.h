#ifndef NETWORK_H
#define NETWORK_H

#include "QString"
#include "QAbstractSocket"
#include "QTcpSocket"
#include <iostream>

using namespace std;

class Network
{
private:
    QString adresseIp;
    QString port;
    QTcpSocket *socket;// Représente le serveur
    quint16 tailleMessage;
public:
    Network(const QString ip, const QString p);

    QString getAdresseIp() const;
    QString getPort() const;

    void setAdresseIp(const QString ip);
    void setPort(const QString p);

    void close();
    void received();
    void send(QString s);
    void connecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);
};

#endif // NETWORK_H
