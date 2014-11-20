#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initialisation de la vue
    ui->setupUi(this);
    //Initialisation de la socket
    socket = new QTcpSocket(this);
    //Attribution des signaux aux différents évenements
    connect(socket, SIGNAL(readyRead()), this, SLOT(received()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    connect(ui->btnEnvoyer,SIGNAL(clicked()),this,SLOT(send()));
    connect(ui->btnAdd,SIGNAL(clicked()),this, SLOT(addFormulaire()));
    //Initialisation de la liste des objets dispo
    ui->listeObjets->addItem("Point");
    ui->listeObjets->addItem("Segment");
    ui->listeObjets->addItem("Carré");
    ui->listeObjets->addItem("Rectangle");
    ui->listeObjets->addItem("Rond");
    ui->listeObjets->addItem("Ellipse");
    //Initialisation de la taille du message reçu
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

void MainWindow::addFormulaire()
{

}
