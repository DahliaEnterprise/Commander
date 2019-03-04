#include "game_to_opengl_image.h"

game_to_opengl_image::game_to_opengl_image(QObject *parent) : QObject(parent)
{

}

//Setup game to opengl image
void game_to_opengl_image::setup(QString setfilename, int setx, int sety, int setwidth, int setheight, int setscale)
{
    filename.clear();filename.append(setfilename);
    x = QString::number(setx).toDouble();
    y = QString::number(sety).toDouble();
    width = setwidth;
    height = setheight;
    scale = setscale;
    pixmap = QPixmap(filename);
    image = pixmap.toImage();
    blankPixmap = QPixmap();
    bool scaled_bool = false;
    if(scale == 1){ scaled_bool = true; }
    if(scaled_bool == true){ image = image.scaled(width, height); }
}


void game_to_opengl_image::setup(QPixmap setpixmap, int setx, int sety, int setwidth, int setheight, int setscale)
{
    x = QString::number(setx).toDouble();
    y = QString::number(sety).toDouble();
    width = setwidth;
    height = setheight;
    scale = setscale;
    pixmap = setpixmap;
    blankPixmap = QPixmap();
    image = pixmap.toImage();
    bool scaled_bool = false;
    if(scale == 1){ scaled_bool = true; }
    if(scaled_bool == true){ image = image.scaled(width, height); }
}

void game_to_opengl_image::resetPixmap(QPixmap setpixmap)
{
    pixmap = setpixmap;
}

//Update coordinates
void game_to_opengl_image::updateCoordinates(double newx, double newy)
{
    x = newx;
    y = newy;
}

//Toggle showing/hiding image
void game_to_opengl_image::show(bool state)
{
    if(state == true){
        image = pixmap.toImage();
    }else if(state == false)
    {
        image = blankPixmap.toImage();
    }
}

//Invoked by game to opengl class to paint on its painter.
void game_to_opengl_image::paint(QPainter* painter){ painter->drawImage(QRectF(x, y, width, height), image); }

//Compute bounding box.
QRect game_to_opengl_image::get_bounding_box()
{
    QRect output(QString::number(x).toInt(), QString::number(y).toInt(), image.width(), image.height());
}
