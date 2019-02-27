#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QTimer>
#include "cardgame/opengl/opengl_canvas.h"
#include "cardgame/gamelogic/mainmenu/gamelogic_mainmenu.h"
class gamelogic : public QObject
{
    Q_OBJECT
public:
    explicit gamelogic(opengl_canvas* setLogic, QObject *parent = nullptr);
    void start();
    void game_update(QPoint mouseposition);

private:
    QTimer* updatetimer;

    int currentPage = 0;

    QList<game_to_opengl*> game_to_opengl_draw_list;

    //Graphical User Interfaces
    gamelogic_mainmenu* gui_mainmenu;

    //Global scope
    opengl_canvas* canvas;

signals:

private slots:

};
#endif // GAMELOGIC_H
