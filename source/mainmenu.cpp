#include "mainmenu.h"

mainmenu::mainmenu(QWidget *parent) : QWidget(parent)
{

}

void mainmenu::start()
{
    //Initialize applications
    gui_find = new class find(); gui_find->start(); gui_find->setWindowTitle("Find Files");

    //Apply Layout
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(layout);

    QLabel* header = new QLabel(QString("<p align=\"center\" font-size=\"9px\">Created By Shane Betz</p>"));
    layout->addWidget(header);

    QPixmap creatorImagePixmap(":resources/creator.jpg");
    QLabel* creatorImage = new QLabel();creatorImage->setPixmap(creatorImagePixmap);
    layout->addWidget(creatorImage);

    QWidget* panel_of_buttons_widget = new QWidget();
    panel_of_buttons_layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    panel_of_buttons_widget->setLayout(panel_of_buttons_layout);
    layout->addWidget(panel_of_buttons_widget);

    button_find = new QPushButton(QString("Find"), nullptr);
    layout->addWidget(button_find);

    //Connect functionality to buttons.
    QObject::connect(button_find, SIGNAL(clicked()), this, SLOT(show_find_window()));
}

void mainmenu::show_find_window(){ gui_find->show(); }
