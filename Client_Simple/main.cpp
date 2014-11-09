#include "network.h"
#include <QApplication>
#include "Headers/Cercle.h"
#include "Headers/Couleur.h"
#include "Headers/Figure.h"
#include "Headers/Groupe.h"
#include "Headers/Point.h"
#include "Headers/Polygone.h"
#include "Headers/Segment.h"
#include "Headers/Triangle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Network *network = new Network("127.0.0.1","2107");


    return a.exec();
}
