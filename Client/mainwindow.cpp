#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(received()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    connect(ui->btnEnvoyer,SIGNAL(clicked()),this,SLOT(send()));
    tailleMessage = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send()
{
    socket->abort();
    socket->connectToHost(ui->adresseIp->text(), ui->port->value());
    /*QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out<<"";
    socket->write(paquet);*/

    QByteArray paquet1;
    QDataStream out1(&paquet1, QIODevice::WriteOnly);

    QString messageAEnvoyer = ui->nom->text();

    out1 << messageAEnvoyer;

    socket->write(paquet1);
    socket->close();
}

void MainWindow::received()
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


void MainWindow::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur)
    {
        case QAbstractSocket::HostNotFoundError:
             QMessageBox::critical(this, "Erreur", "Serveur inexistant.");
            break;
        case QAbstractSocket::ConnectionRefusedError:
             QMessageBox::critical(this, "Erreur", "Connexion refusée.");
            break;
        case QAbstractSocket::RemoteHostClosedError:
             QMessageBox::critical(this, "Erreur", "Connexion fermée.");
            break;
        default:
             QMessageBox::critical(this, "Erreur", socket->errorString());
    }
}

void MainWindow::connecte()
{
    //QMessageBox::information(this, "Information", "Connexion avec le serveur réussie.");
}
