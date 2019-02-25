#ifndef OPENGL_CANVAS_H
#define OPENGL_CANVAS_H

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QColor>
#include <QImage>
#include "cardgame/game_to_opengl/game_to_opengl.h"
#include "cardgame/game_to_opengl/game_to_opengl_image.h"
class opengl_canvas
{
public:
    opengl_canvas();
    void initialize();
    void sustain_image(QList<game_to_opengl*> setObjectsToSustainOnScreen);
    void paint(QPainter *painter, QPaintEvent *event, qint64 milisecondsSinceLastPaint);

private:
    QStringList objectsToSustainOnScreen;
    QList<game_to_opengl*> ObjectsToSustainOnScreen;
};

#endif // OPENGL_CANVAS_H
