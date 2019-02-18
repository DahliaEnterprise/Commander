#include "mainmenu.h"

mainmenu::mainmenu(QWidget *parent) : QWidget(parent)
{

}

void mainmenu::start()
{
    //Initialize applications
    gui_find = new class find(); gui_find->start(); gui_find->setWindowTitle("Find");

    //Apply Layout
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(layout);

    QLabel* header = new QLabel(QString("<h2>Dahlias' Commander</h2>"));
    layout->addWidget(header);

    button_find = new QPushButton(QString("Find"), nullptr);
    layout->addWidget(button_find);

    //Connect functionality to buttons.
    QObject::connect(button_find, SIGNAL(clicked()), this, SLOT(show_find_window()));
}

void mainmenu::show_find_window(){ gui_find->show(); }
