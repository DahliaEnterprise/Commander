#include "mainmenu_indicator_of_selectedwindow.h"

mainmenu_indicator_of_selectedWindow::mainmenu_indicator_of_selectedWindow(QObject *parent) : QObject(parent)
{

}

void mainmenu_indicator_of_selectedWindow::start()
{
    indicator_container = new game_to_opengl();
    indicator_image = new game_to_opengl_image();
    indicator_image->setup(QString(":/resources/mainmenu/cardcreation/selectedcards_selected_indicator.png"), 0, 0, 856, 630, 1);
    indicator_container->containImage(indicator_image);
}

void mainmenu_indicator_of_selectedWindow::selected_window(int window_selected)
{
    if(window_selected == 3)
    {
        indicator_image->updateCoordinates(1040, 112);
    }
}

game_to_opengl* mainmenu_indicator_of_selectedWindow::game_to_opengl_object(){ return indicator_container; }
