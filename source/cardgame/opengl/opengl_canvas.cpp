#include "opengl_canvas.h"

opengl_canvas::opengl_canvas()
{

}

void opengl_canvas::initialize()
{
    ObjectsToSustainOnScreen = QList<game_to_opengl*>();
}


void opengl_canvas::paint(QPainter *painter, QPaintEvent *event)
{
    //Loop through "Objects To Sustain On Screen". Begining of list is the back most layer, end is the front most layer.
    QList<game_to_opengl*>::const_iterator objects_iterator = ObjectsToSustainOnScreen.constBegin();
    while(objects_iterator != ObjectsToSustainOnScreen.constEnd())
    {
        game_to_opengl* draw_command_container = *objects_iterator;
        draw_command_container->paint(painter);
        objects_iterator++;
    }
}

void opengl_canvas::sustain_image(QList<game_to_opengl*> setObjectsToSustainOnScreen)
{
    ObjectsToSustainOnScreen.clear(); ObjectsToSustainOnScreen = setObjectsToSustainOnScreen;

    /**
    ObjectsToSustainOnScreen.clear();
    QList<game_to_opengl*>::const_iterator iterator = setObjectsToSustainOnScreen.constBegin();
    while(iterator != setObjectsToSustainOnScreen.constEnd())
    {
        game_to_opengl* draw_command_container = *iterator;
        ObjectsToSustainOnScreen.append(draw_command_container);
        iterator++;
    }
    **/
}
