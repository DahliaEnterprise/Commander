#include "window_playagainstai.h"

window_playAgainstAI::window_playAgainstAI(QWidget *parent) : QWidget(parent)
{

}


void window_playAgainstAI::start()
{
    /** [Initialize Objects] **/
    canvas = new opengl_canvas();
    openglWidget = new opengl_widget(canvas);
    openglWidget->initalizeWidget();

    /** Configure Window (Likely to be move to open gl widget canvas though **/
    this->setWindowTitle("Cardgame Against Artificial Inteligence");

    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    layout->setAlignment(Qt::AlignTop);
    this->setLayout(layout);

    layout->addWidget(openglWidget);

    update_trigger = new QTimer();
    QObject::connect(update_trigger, SIGNAL(timeout()), openglWidget, SLOT(slotUpdate()));
    update_trigger->start(50);

    /** [Fullscreen] **/
    this->move(0, 0);
    QDesktopWidget* desktop = QApplication::desktop();
    int screen_width = desktop->width();
    int screen_height = desktop->height();
    this->setFixedSize(screen_width, screen_height);

    /** [Transparent Window] **/
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_NoSystemBackground, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    /** [Setup Board] **
    QPixmap actioncard_top_pixmap(QString(":/resources/cards/card-creature-dragon.png"));
    actioncard_top = new QLabel(); actioncard_top->setPixmap(actioncard_top_pixmap.scaledToWidth(200));  actioncard_top->setFixedSize(100,100); actioncard_top->move(200, 200);layout->addWidget(actioncard_top);
    **/
}
