#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainmenu* mainMenu = new mainmenu(nullptr);
    mainMenu->start();
    mainMenu->setWindowTitle(QString("Commander By Dahlia Enterprise"));
    mainMenu->show();

    return a.exec();
}
