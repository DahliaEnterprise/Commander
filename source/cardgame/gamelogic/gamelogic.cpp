#include "gamelogic.h"

gamelogic::gamelogic(opengl_canvas* setCanvas, QObject *parent) : QObject(parent)
{
    canvas = setCanvas;
}

void gamelogic::start()
{
    /** [Initalize Objects] **/
    gui_mainmenu = new gamelogic_mainmenu();
    gui_mainmenu->start();

    /** Start logic loop **/
    //Update timer ensures that if the chain of envoking cycle_logic breaks, it will start within the next timers timeout.
    /*updatetimer = new QTimer();
    updatetimer->start(100);
    QObject::connect(updatetimer, SIGNAL(timeout()), this, SLOT(wakeLogic()));*/
}


void gamelogic::game_update(QPoint mouseposition)
{
    //Begin adding elements from first to last, back of image to front of image.
    if(currentPage == 0){ gui_mainmenu->render(mouseposition, game_to_opengl_draw_list); }

    //Instruct canvas to sustain the draw list until the next sustain image function is called.
    canvas->sustain_image(game_to_opengl_draw_list);
}
