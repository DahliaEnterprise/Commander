#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <QPainter>
#include <QDateTime>
#include "cardgame/opengl/opengl_canvas.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
class opengl_widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    opengl_widget(opengl_canvas* setCanvas);
    void initalizeWidget();
    void gpu_update();

private:
    //Global Scope
    opengl_canvas* canvas;

protected:
    void paintEvent(QPaintEvent *event) override;
    void close(QCloseEvent* event);

public slots:
};

#endif // OPENGL_WIDGET_H
