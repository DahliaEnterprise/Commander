#include "mainmenu_mouse.h"

mainmenu_mouse::mainmenu_mouse(QObject *parent) : QObject(parent)
{

}

void mainmenu_mouse::start()
{
    mouse_container = new game_to_opengl();
    mouse_image = new game_to_opengl_image();
    mouse_image->setup(QString(":/resources/mainmenu/cardcreation/mouse/mouse-pointer.png"), 0, 0, 100, 100, 1);
    mouse_container->containImage(mouse_image);
}

void mainmenu_mouse::update(QPoint mousePosition){
    mouse_image->updateCoordinates(mousePosition.x()-70, mousePosition.y());
}

game_to_opengl* mainmenu_mouse::game_to_opengl_object(){ return mouse_container;}
