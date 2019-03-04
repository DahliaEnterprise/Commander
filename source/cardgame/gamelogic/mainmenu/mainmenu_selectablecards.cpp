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
}

void mainmenu_selectablecards::update(QPoint mousePosition)
{
    qDebug() << mousePosition;
    QPainter painter(&image);


    selectable_cards_image->resetPixmap(QPixmap::fromImage(image));
}

game_to_opengl* mainmenu_selectablecards::game_to_opengl_object()
{
    return selectable_cards_container;
}
