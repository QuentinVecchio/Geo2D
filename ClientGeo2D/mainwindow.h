#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QAbstractSocket"
#include "QTcpSocket"
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
        void received();
        void send();
        void connecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);
        void addFormulaire();
private:
        QTcpSocket *socket; // Représente le serveur
        quint16 tailleMessage;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
