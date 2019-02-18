#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainmenu* mainMenu = new mainmenu(nullptr);
    mainMenu->start();
    mainMenu->setWindowTitle(QString("Dahlia - Commander"));
    mainMenu->show();

    return a.exec();
}
