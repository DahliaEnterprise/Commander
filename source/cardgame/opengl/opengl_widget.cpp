#include "opengl_widget.h"

opengl_widget::opengl_widget(opengl_canvas* setCanvas)
{
    canvas = setCanvas;
}

void opengl_widget::initalizeWidget()
{
    this->move(0, 0);
    QDesktopWidget* desktop = QApplication::desktop();
    int screen_width = desktop->width();
    int screen_height = desktop->height();
    this->setFixedSize(screen_width, screen_height);
    this->setAutoFillBackground(false);
    //this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //this->setAttribute(Qt::WA_NoSystemBackground, true);
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_AlwaysStackOnTop);

    this->setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);

    QSurfaceFormat surface = this->format();
    surface.setSamples(8);
    surface.setSwapBehavior(QSurfaceFormat::TripleBuffer);
    this->setFormat(surface);
}

void opengl_widget::paintEvent(QPaintEvent* event)
{
    //Initalize and Setup Painter
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    //Render
    canvas->paint(&painter, event);
    //Clear resources
    painter.end();
}

void opengl_widget::close(QCloseEvent* event)
{

}

void opengl_widget::gpu_update(){

    update();
}
