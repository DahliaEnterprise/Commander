#include "window_playagainstai.h"

window_playAgainstAI::window_playAgainstAI(QWidget *parent) : QWidget(parent)
{

}


void window_playAgainstAI::start()
{
    /** [Initialize Objects] **/
    canvas = new opengl_canvas();
    canvas->initialize();
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
    update_trigger->start(1);

    //Temporary board setup draw commands
    /** DEPRECATED
    QStringList draw_list = QStringList();
    draw_list.append(QString("image:\"c291cmNlPTovcmVzb3VyY2VzL2NhcmRzL2NhcmQtY3JlYXR1cmUtZHJhZ29uLnBuZzt3aWR0aD01MTI7aGVpZ2h0PTI4ODt4PTIwMDt5PTcwMDtzY2FsZWQ9MTs=\""));
    draw_list.append(QString("image:\"c291cmNlPTovcmVzb3VyY2VzL2NhcmRzL2FjdGl2YXRlZC1jYXJkLWJhc2UtYXR0YWNrLnBuZzt3aWR0aD02MTI7aGVpZ2h0PTc5Mjt4PTIwMDt5PTEwMDtzY2FsZWQ9MTs==\""));
    canvas->sustain_image(draw_list);
    **/

    /** DEPRECATED,
    image = new game_to_opengl_image();
    QList<T> draw_list = QList<T>();
    draw_list.append(image);
    **/

    game_to_opengl_draw_list = QList<game_to_opengl*>();

    //Image one
    game_to_opengl_image* imageone = new game_to_opengl_image();
    imageone->setup(QString(":/resources/cards/card-creature-dragon.png"), 212, 600, 500, 288, 1);
    game_to_opengl* imageone_opengl_container = new game_to_opengl();
    imageone_opengl_container->containImage(imageone);
    game_to_opengl_draw_list.append(imageone_opengl_container);

    //Image two
    game_to_opengl_image* imagetwo = new game_to_opengl_image();
    imagetwo->setup(QString(":/resources/cards/activated-card-base-attack.png"), 112, 100, 100, 288, 1);
    game_to_opengl* imagetwo_opengl_container = new game_to_opengl();
    imagetwo_opengl_container->containImage(imagetwo);
    game_to_opengl_draw_list.append(imagetwo_opengl_container);

    canvas->sustain_image(game_to_opengl_draw_list);

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
