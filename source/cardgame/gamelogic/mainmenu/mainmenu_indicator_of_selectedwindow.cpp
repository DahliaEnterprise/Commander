#include "mainmenu_indicator_of_selectedwindow.h"

mainmenu_indicator_of_selectedWindow::mainmenu_indicator_of_selectedWindow(QObject *parent) : QObject(parent)
{

}

void mainmenu_indicator_of_selectedWindow::start()
{
    currentSelectedWindow = 0;
    currently_selected_deck_container = new game_to_opengl();
    currently_selected_deck_image = new game_to_opengl_image();
    currently_selected_deck_image->setup(QString(":/resources/mainmenu/cardcreation/currentlyselecteddeck_selected_indicator.png"), 530, 112, 503, 621, 1);
    currently_selected_deck_container->containImage(currently_selected_deck_image);
    currently_selected_deck_image->show(false);

    selectable_cards_container = new game_to_opengl();
    selectable_cards_image = new game_to_opengl_image();
    selectable_cards_image->setup(QString(":/resources/mainmenu/cardcreation/selectedcards_selected_indicator.png"), 1040, 112, 856, 630, 1);
    selectable_cards_container->containImage(selectable_cards_image);
    currently_selected_deck_image->show(false);

    blank_container = new game_to_opengl();
    blank_image = new game_to_opengl_image();
    QPixmap pixmap2;
    pixmap2.fill(QColor(0,0,0,0));
    blank_image->setup(pixmap2, 0,0, 1,1,1);
}

void mainmenu_indicator_of_selectedWindow::selected_window(int window_selected)
{
    currentSelectedWindow = window_selected;

    if(window_selected == 3)
    {
        currently_selected_deck_image->show(false);
        selectable_cards_image->show(true);
        blank_image->show(false);
    }else if(window_selected == 2)
    {
        currently_selected_deck_image->show(true);
        selectable_cards_image->show(false);
        blank_image->show(false);
    }else if(window_selected == 0)
    {
        currently_selected_deck_image->show(false);
        selectable_cards_image->show(false);
        blank_image->show(true);
    }
}

game_to_opengl* mainmenu_indicator_of_selectedWindow::game_to_opengl_object()
{
    if(currentSelectedWindow == 3){ return selectable_cards_container; }else if(currentSelectedWindow == 2){ return currently_selected_deck_container; }else if(currentSelectedWindow == 0){ return blank_container; };
}
