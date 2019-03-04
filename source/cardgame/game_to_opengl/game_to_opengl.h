#ifndef GAME_TO_OPENGL_H
#define GAME_TO_OPENGL_H

#include <QObject>
#include <QPainter>
#include "cardgame/game_to_opengl/game_to_opengl_image.h"

class game_to_opengl : public QObject
{
    Q_OBJECT
public:
    explicit game_to_opengl(QObject *parent = nullptr);
    void containImage(game_to_opengl_image* setImage);
    void paint(QPainter* painter);
    QRect get_bounding_box();

private:
    int datatype;//0=not set; 1 = image;
    game_to_opengl_image* image;

signals:

public slots:
};

#endif // GAME_TO_OPENGL_H
