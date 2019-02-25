#include "opengl_canvas.h"

opengl_canvas::opengl_canvas()
{

}


void opengl_canvas::paint(QPainter *painter, QPaintEvent *event, qint64 milisecondsSinceLastPaint)
{
    //Probubly need to make it so paint will sustain "committed" arrangements, while it takes input somehow of the objects to sustain.
    QImage image(QString(":/resources/cards/card-creature-dragon.png"));
    painter->drawImage(200, 600, image);

    /**
    QPen pen = painter->pen();
    pen.setColor(QColor(100,100,100));
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    painter->drawRect(QRect(0,0, 100, 100));

    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);
    painter->drawRect(QRect(0,0,100,100));
    **/
}
