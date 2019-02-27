#ifndef MAINMENU_MOUSE_H
#define MAINMENU_MOUSE_H

#include <QObject>

class mainmenu_mouse : public QObject
{
    Q_OBJECT
public:
    explicit mainmenu_mouse(QObject *parent = nullptr);
    void start();

private:
    game_to_opengl* mouse_container;

signals:

public slots:
};

#endif // MAINMENU_MOUSE_H
