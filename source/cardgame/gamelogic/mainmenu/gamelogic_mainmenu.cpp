#include "gamelogic_mainmenu.h"

gamelogic_mainmenu::gamelogic_mainmenu(QObject *parent) : QObject(parent)
{

}

void gamelogic_mainmenu::start()
{
    bgimage = new game_to_opengl_image();
    bgimage->setup(QString(":/resources/mainmenu/cardcreation/mainmenu-cardcreation.png"), 0, 0, 1920, 1080, 1);
    bgimage_opengl_container = new game_to_opengl();
    bgimage_opengl_container->containImage(bgimage);

    indicator_of_selectedwindow = new mainmenu_indicator_of_selectedWindow();
    indicator_of_selectedwindow->start();
}

void gamelogic_mainmenu::render(QPoint mousePosition, QList<game_to_opengl*>& list)
{
        list.clear();

        //Background image
        list.append(bgimage_opengl_container);

        //Indicate which window is activate
        indicator_of_selectedwindow->selected_window(3);
        list.append(indicator_of_selectedwindow->game_to_opengl_object());


        //Image two
        /*game_to_opengl_image* imagetwo = new game_to_opengl_image();
        imagetwo->setup(QString(":/resources/cards/activated-card-base-attack.png"), 280, 200, 100, 188, 1);
        game_to_opengl* imagetwo_opengl_container = new game_to_opengl();
        imagetwo_opengl_container->containImage(imagetwo);
        list.append(imagetwo_opengl_container);

        //Image Three
        game_to_opengl_image* imagethree = new game_to_opengl_image();
        imagethree->setup(QString(":/resources/cards/card-creature-beastman.png"), 1400, 800, 500, 288, 1);
        game_to_opengl* imagethree_opengl_container = new game_to_opengl();
        imagethree_opengl_container->containImage(imagethree);
        list.append(imagethree_opengl_container);

        //Image "Keyboard Button Q"
        game_to_opengl_image* keyboard_button_q = new game_to_opengl_image();
        keyboard_button_q->setup(QString(":/resources/keyboard buttons/q button.png"), 200, 250, 50, 50, 1);
        game_to_opengl* keyboard_button_q_opengl_container = new game_to_opengl();
        keyboard_button_q_opengl_container->containImage(keyboard_button_q);
        list.append(keyboard_button_q_opengl_container);

        //Image "activated card"
        game_to_opengl_image* imagefour = new game_to_opengl_image();
        imagefour->setup(QString(":/resources/cards/activated-card-base-attack.png"), 170, 350, 100, 188, 1);
        game_to_opengl* imagefour_opengl_container = new game_to_opengl();
        imagefour_opengl_container->containImage(imagefour);
        list.append(imagefour_opengl_container);
        */
}
