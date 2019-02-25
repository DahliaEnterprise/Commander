#include "opengl_widget.h"

opengl_widget::opengl_widget(opengl_canvas* setCanvas)
{
    timestampLastPaintEvent = 0;
    canvas = setCanvas;
}

void opengl_widget::initalizeWidget()
{
    timestampLastPaintEvent = QDateTime::currentMSecsSinceEpoch();
    this->move(0, 0);
    QDesktopWidget* desktop = QApplication::desktop();
    int screen_width = desktop->width();
    int screen_height = desktop->height();
    this->setFixedSize(screen_width, screen_height);
    this->setAutoFillBackground(false);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_NoSystemBackground, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_AlwaysStackOnTop);
}

void opengl_widget::paintEvent(QPaintEvent* event)
{
    //Initalize and Setup Painter
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //Render
    qint64 timeSinceLastPaintEvent_int64 = QDateTime::currentMSecsSinceEpoch() - timestampLastPaintEvent;
    canvas->paint(&painter, event, timeSinceLastPaintEvent_int64);
    //Clear resources
    painter.end();
}

void opengl_widget::slotUpdate()
{
    update();
}
