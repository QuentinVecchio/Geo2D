#include "network.h"

Network::Network(const QString ip, const QString p)
{
    this->adresseIp = ip;
    this->port = p;
    this->socket = new QTcpSocket();
    tailleMessage = 0;
}

void Network::close()
{
   this->socket->close();
}

QString Network::getAdresseIp() const
{
    return this->adresseIp;
}

QString Network::getPort() const
{
    return this->port;
}

void Network::setAdresseIp(const QString ip)
{
    this->adresseIp = ip;
}

void Network::setPort(const QString p)
{
    this->port = p;
}

void Network::send(QString s)
{
    socket->abort();
    socket->connectToHost(this->adresseIp,this->port.toInt());
    QByteArray paquet1;
    QDataStream out1(&paquet1, QIODevice::WriteOnly);
    QString messageAEnvoyer = s;
    out1 << messageAEnvoyer;
    socket->write(paquet1);
    this->close();
}

void Network::received()
{
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;
    QString messageRecu;
    in >> messageRecu;
    tailleMessage = 0;
}


void Network::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur)
    {
        case QAbstractSocket::HostNotFoundError:
            cout << "Serveur inexistant." << endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            cout <<  "Connexion refusée." << endl;
            break;
        case QAbstractSocket::RemoteHostClosedError:
             cout << "Connexion fermée." << endl;
            break;
        default:
             cout <<  "Erreur socket" << endl;
    }
}

void Network::connecte()
{
    //QMessageBox::information(this, "Information", "Connexion avec le serveur réussie.");
}
