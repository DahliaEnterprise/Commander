#include "cardgame.h"

cardgame::cardgame(QWidget *parent) : QWidget(parent)
{

}

void cardgame::start()
{
    /** Initalize Objects **/
    playAgainstAI = new window_playAgainstAI();
    playAgainstAI->start();

    /** Define Layout **/
    this->setFixedSize(450, 200);
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(layout);

    button_configuration = new QPushButton(QString("Configuration"));
    button_configuration->setFixedSize(400, 50);
    layout->addWidget(button_configuration);

    button_playAgainstAI = new QPushButton(QString("Play Against Artificial Intelligence"));
    button_playAgainstAI->setFixedSize(400, 50);
    layout->addWidget(button_playAgainstAI);

    button_playAgainstHuman = new QPushButton(QString("Play over a network"));
    button_playAgainstHuman->setFixedSize(400, 50);
    button_playAgainstHuman->setDisabled(true);
    layout->addWidget(button_playAgainstHuman);

    QObject::connect(button_playAgainstAI, SIGNAL(clicked()), this, SLOT(show_playAgainstAI()));

}

void cardgame::show_playAgainstAI()
{
    this->hide();
    playAgainstAI->show();
}
