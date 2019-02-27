#include "mainmenu_mouse.h"

mainmenu_mouse::mainmenu_mouse(QObject *parent) : QObject(parent)
{

}

void mainmenu_mouse::start()
{
    mouse_container = new game_to_opengl();
}
