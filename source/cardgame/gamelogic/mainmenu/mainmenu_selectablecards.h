#ifndef MAINMENU_SELECTABLECARDS_H
#define MAINMENU_SELECTABLECARDS_H

#include <QObject>
#include "cardgame/game_to_opengl/game_to_opengl.h"
#include "cardgame/game_to_opengl/game_to_opengl_image.h"
#include <QDebug>
#include <QImage>
#include "cardgame/database/database.h"
class mainmenu_selectablecards : public QObject
{
    Q_OBJECT
public:
    explicit mainmenu_selectablecards(database* setdb, QObject *parent = nullptr);
    void start();
    void update(QPoint mousePosition);
    game_to_opengl* game_to_opengl_object();

private:
    game_to_opengl* selectable_cards_container;
    game_to_opengl_image* selectable_cards_image;
    QImage image;

    //Global scope
    database* db;

signals:

public slots:

};

#endif // MAINMENU_SELECTABLECARDS_H
