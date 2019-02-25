#ifndef WINDOW_PLAYAGAINSTAI_H
#define WINDOW_PLAYAGAINSTAI_H

#include <QWidget>
#include <QDesktopWidget>
#include <QApplication>
#include <QLabel>
#include <QBoxLayout>
#include <QPixmap>
#include "opengl/opengl_widget.h"
#include "opengl/opengl_canvas.h"
#include <QTimer>
#include "game_to_opengl/game_to_opengl.h"
#include "game_to_opengl/game_to_opengl_image.h"
#include <QList>
class window_playAgainstAI : public QWidget
{
    Q_OBJECT
public:
    explicit window_playAgainstAI(QWidget *parent = nullptr);
    void start();

private:
    opengl_widget* openglWidget;
    opengl_canvas* canvas;
    QTimer* update_trigger;

    QBoxLayout* layout;

    QList<game_to_opengl*> game_to_opengl_draw_list;


signals:

public slots:
};

#endif // WINDOW_PLAYAGAINSTAI_H
