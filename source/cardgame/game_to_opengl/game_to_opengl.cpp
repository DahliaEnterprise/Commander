#include "game_to_opengl.h"

game_to_opengl::game_to_opengl(QObject *parent) : QObject(parent)
{
    datatype = 0;
}

void game_to_opengl::containImage(game_to_opengl_image* setImage)
{
    datatype = 1;
    image = setImage;
}

void game_to_opengl::paint(QPainter* painter)
{
    if(datatype == 1)
    {
        //paint image
        image->paint(painter);
    }
}
