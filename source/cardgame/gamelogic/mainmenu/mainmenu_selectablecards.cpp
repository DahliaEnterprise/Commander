#include "mainmenu_selectablecards.h"

mainmenu_selectablecards::mainmenu_selectablecards(database* setdb, QObject *parent) : QObject(parent)
{
    db = setdb;
}

void mainmenu_selectablecards::start()
{
    selectable_cards_container = new game_to_opengl();
    selectable_cards_image = new game_to_opengl_image();
    selectable_cards_container->containImage(selectable_cards_image);
    managerTimer = new QTimer();
    managerTimer->setInterval(100);
    QObject::connect(managerTimer, SIGNAL(timeout()), this, SLOT(slotManager()));
}

void mainmenu_selectablecards::update(QPoint mousePosition)
{
    QPainter painter(&image);



    selectable_cards_image->resetPixmap(QPixmap::fromImage(image));
}

game_to_opengl* mainmenu_selectablecards::game_to_opengl_object()
{
    return selectable_cards_container;
}

void mainmenu_selectablecards::slotManager()
{
    QList<database_card*> turnActivatedCardList = db->get_turnActivatedCardList();
    QList<database_card*>::const_iterator iterator = turnActivatedCardList.constBegin();
    while(iterator != turnActivatedCardList.constEnd())
    {


        iterator++;
    }
}
