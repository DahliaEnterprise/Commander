#include "game_to_opengl_image.h"

game_to_opengl_image::game_to_opengl_image(QObject *parent) : QObject(parent)
{

}

void game_to_opengl_image::setup(QString setfilename, int setx, int sety, int setwidth, int setheight, int setscale)
{
    filename.clear();filename.append(setfilename);
    x = QString::number(setx).toDouble();
    y = QString::number(sety).toDouble();
    width = setwidth;
    height = setheight;
    scale = setscale;
    image = QImage(filename);
    bool scaled_bool = false;
    if(scale == 1){ scaled_bool = true; }
    if(scaled_bool == true){ image = image.scaled(width, height); }
}

void game_to_opengl_image::setup(QPixmap pixmap, int setx, int sety, int setwidth, int setheight, int setscale)
{
    x = QString::number(setx).toDouble();
    y = QString::number(sety).toDouble();
    width = setwidth;
    height = setheight;
    scale = setscale;
    image = pixmap.toImage();
    bool scaled_bool = false;
    if(scale == 1){ scaled_bool = true; }
    if(scaled_bool == true){ image = image.scaled(width, height); }
}

void game_to_opengl_image::updateCoordinates(double newx, double newy)
{
    x = newx;
    y = newy;
}

void game_to_opengl_image::paint(QPainter* painter){ painter->drawImage(QRectF(x, y, width, height), image); }
