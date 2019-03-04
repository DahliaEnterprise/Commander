#ifndef MAINMENU_MOUSE_H
#define MAINMENU_MOUSE_H

#include <QObject>
#include "cardgame/game_to_opengl/game_to_opengl.h"
#include "cardgame/game_to_opengl/game_to_opengl_image.h"

class mainmenu_mouse : public QObject
{
    Q_OBJECT
public:
    explicit mainmenu_mouse(QObject *parent = nullptr);
    void start();
    void update(QPoint mousePosition);
    game_to_opengl* game_to_opengl_object();

private:
    game_to_opengl* mouse_container;
    game_to_opengl_image* mouse_image;


signals:

public slots:
};

#endif // MAINMENU_MOUSE_H
