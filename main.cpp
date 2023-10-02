#include "sosgame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SOSGame w;
    w.show();
    return a.exec();
}
