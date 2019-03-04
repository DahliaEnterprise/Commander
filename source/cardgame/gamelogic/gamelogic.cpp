#include "gamelogic.h"

gamelogic::gamelogic(database* setdb, opengl_canvas* setCanvas, QObject *parent) : QObject(parent)
{
    db = setdb;
    canvas = setCanvas;
}

void gamelogic::start()
{
    /** [Initalize Objects] **/
    gui_mainmenu = new gamelogic_mainmenu(db);
    gui_mainmenu->start();
}


void gamelogic::game_update(QPoint mouseposition)
{
    //Begin adding elements from first to last, back of image to front of image.
    if(currentPage == 0){ gui_mainmenu->render(mouseposition, game_to_opengl_draw_list); }

    //Instruct canvas to sustain the draw list until the next sustain image function is called.
    canvas->sustain_image(game_to_opengl_draw_list);
}

void gamelogic::get_bounding_box()
{

}
