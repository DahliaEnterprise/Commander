#ifndef MAINMENU_INDICATOR_OF_SELECTEDWINDOW_H
#define MAINMENU_INDICATOR_OF_SELECTEDWINDOW_H

#include <QObject>
#include "cardgame/game_to_opengl/game_to_opengl.h"
#include "cardgame/game_to_opengl/game_to_opengl_image.h"
#include <QCursor>
#include <QDebug>

class mainmenu_indicator_of_selectedWindow : public QObject
{
    Q_OBJECT
public:
    explicit mainmenu_indicator_of_selectedWindow(QObject *parent = nullptr);
    void start();
    void selected_window(int window_selected);
    game_to_opengl* game_to_opengl_object();

private:
    QPixmap pixmap;
    game_to_opengl* output_image_container;
    game_to_opengl_image* output_image;

    game_to_opengl* mouse_container;
    game_to_opengl_image* mouse_image;

    game_to_opengl* currently_selected_deck_container;
    game_to_opengl_image* currently_selected_deck_image;

    game_to_opengl* selectable_cards_container;
    game_to_opengl_image* selectable_cards_image;

    game_to_opengl* blank_container;
    game_to_opengl_image* blank_image;

    int currentSelectedWindow;

signals:

public slots:
};

#endif // MAINMENU_INDICATOR_OF_SELECTEDWINDOW_H
