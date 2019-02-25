#ifndef OPENGL_CANVAS_H
#define OPENGL_CANVAS_H

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QColor>
#include <QImage>
class opengl_canvas
{
public:
    opengl_canvas();
    void paint(QPainter *painter, QPaintEvent *event, qint64 milisecondsSinceLastPaint);

private:

};

#endif // OPENGL_CANVAS_H
