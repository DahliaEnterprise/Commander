#include "gamelogic_mainmenu.h"

gamelogic_mainmenu::gamelogic_mainmenu(database* setdb, QObject *parent) : QObject(parent)
{
    db = setdb;
}

void gamelogic_mainmenu::start()
{
    bgimage = new game_to_opengl_image();
    bgimage->setup(QString(":/resources/mainmenu/cardcreation/mainmenu-cardcreation.png"), 0, 0, 1920, 1080, 1);
    bgimage_opengl_container = new game_to_opengl();
    bgimage_opengl_container->containImage(bgimage);

    indicator_of_selectedwindow = new mainmenu_indicator_of_selectedWindow();
    indicator_of_selectedwindow->start();

    selectablecards = new mainmenu_selectablecards(db);
    selectablecards->start();

    mousePointer = new mainmenu_mouse();
    mousePointer->start();
}

void gamelogic_mainmenu::render(QPoint mousePosition, QList<game_to_opengl*>& list)
{
        list.clear();

        //Background image
        list.append(bgimage_opengl_container);

        //Indicate which window is active
        int selected_window = 0;
        if(mousePosition.x() > 520 && mousePosition.x() < 1020)
        {
            selected_window = 2;
        }else if(mousePosition.x() > 1040 && mousePosition.x() < 1900)
        {
            selected_window = 3;
        }

        indicator_of_selectedwindow->selected_window(selected_window);
        list.append(indicator_of_selectedwindow->game_to_opengl_object());

        //Display selectable cards
        list.append(selectablecards->game_to_opengl_object());

        //Mouse pointer
        mousePointer->update(mousePosition);
        list.append(mousePointer->game_to_opengl_object());
}
