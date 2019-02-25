#include "mainmenu.h"

mainmenu::mainmenu(QWidget *parent) : QWidget(parent)
{

}

void mainmenu::start()
{
    //Initialize applications
    gui_find = new class find(); gui_find->start(); gui_find->setWindowTitle("Find Files");
    gui_cardgame = new cardgame(); gui_cardgame->start(); gui_cardgame->setWindowTitle("Card Game");

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
    panel_of_buttons_layout->addWidget(button_find);

    button_cardgame = new QPushButton(QString("Card Game"), nullptr);
    panel_of_buttons_layout->addWidget(button_cardgame);

    //Connect functionality to buttons.
    QObject::connect(button_find, SIGNAL(clicked()), this, SLOT(show_find_window()));
    QObject::connect(button_cardgame, SIGNAL(clicked()), this, SLOT(show_cardgame_window()));
}

void mainmenu::show_find_window(){ gui_find->show(); }
void mainmenu::show_cardgame_window(){ gui_cardgame->show(); }
