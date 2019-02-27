#ifndef GAMELOGIC_MAINMENU_H
#define GAMELOGIC_MAINMENU_H

#include <QObject>
#include "cardgame/opengl/opengl_canvas.h"
#include "cardgame/gamelogic/mainmenu/mainmenu_indicator_of_selectedwindow.h"

class gamelogic_mainmenu : public QObject
{
    Q_OBJECT
public:
    explicit gamelogic_mainmenu(QObject *parent = nullptr);
    void start();
    void render(QPoint mousePosition, QList<game_to_opengl*>& list);

private:
    game_to_opengl_image* bgimage;
    game_to_opengl* bgimage_opengl_container;

    mainmenu_indicator_of_selectedWindow* indicator_of_selectedwindow;

signals:

public slots:
};

#endif // GAMELOGIC_MAINMENU_H