#include "window_playagainstai.h"

window_playAgainstAI::window_playAgainstAI(QWidget *parent) : QWidget(parent)
{

}

window_playAgainstAI::~window_playAgainstAI()
{
    delete keyboardInput;
    delete openglWidget;
    delete canvas;
}


void window_playAgainstAI::start()
{
    QApplication::setOverrideCursor(Qt::BlankCursor);

    timestamp_since_last_logic_cycle = QDateTime::currentMSecsSinceEpoch();

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

    /** [Initialize Objects] **/
    keyboardInput = new playerInput_usingKeyboard();
    canvas = new opengl_canvas();
    canvas->initialize();
    openglWidget = new opengl_widget(canvas);
    openglWidget->initalizeWidget();
    openglWidget->setFixedSize(screen_width, screen_height);
    openglWidget->setStyleSheet(QString("QOpenGLWidget{ margin:0;padding:0; }"));
    logic = new gamelogic(canvas, nullptr);
    logic->start();

    /** Configure Window (Likely to be move to open gl widget canvas though **/
    //Set Window Title
    this->setWindowTitle("Cardgame Against Artificial Inteligence");

    //Define layout as OpenGLWidget
    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    layout->setMargin(0);
    layout->setAlignment(Qt::AlignTop);
    this->setLayout(layout);
    layout->addWidget(openglWidget);

    //Start GPU update cycle
    update_gpu_trigger = new QTimer();
    QObject::connect(update_gpu_trigger, SIGNAL(timeout()), this, SLOT(slotUpdate()));
    update_gpu_trigger->start(1);


    /** DEPRECATED TO BE MOVED TO gamelogic class,
    game_to_opengl_draw_list = QList<game_to_opengl*>();

    //Background image
    game_to_opengl_image* bgimage = new game_to_opengl_image();
    bgimage->setup(QString(":/resources/background.png"), 0, 0, 1920, 1080, 1);
    game_to_opengl* bgimage_opengl_container = new game_to_opengl();
    bgimage_opengl_container->containImage(bgimage);
    game_to_opengl_draw_list.append(bgimage_opengl_container);

    //Image one
    game_to_opengl_image* imageone = new game_to_opengl_image();
    imageone->setup(QString(":/resources/cards/card-creature-dragon.png"), 0, 800, 500, 288, 1);
    game_to_opengl* imageone_opengl_container = new game_to_opengl();
    imageone_opengl_container->containImage(imageone);
    game_to_opengl_draw_list.append(imageone_opengl_container);

    //Image two
    game_to_opengl_image* imagetwo = new game_to_opengl_image();
    imagetwo->setup(QString(":/resources/cards/activated-card-base-attack.png"), 280, 200, 100, 188, 1);
    game_to_opengl* imagetwo_opengl_container = new game_to_opengl();
    imagetwo_opengl_container->containImage(imagetwo);
    game_to_opengl_draw_list.append(imagetwo_opengl_container);

    //Image Three
    game_to_opengl_image* imagethree = new game_to_opengl_image();
    imagethree->setup(QString(":/resources/cards/card-creature-beastman.png"), 1400, 800, 500, 288, 1);
    game_to_opengl* imagethree_opengl_container = new game_to_opengl();
    imagethree_opengl_container->containImage(imagethree);
    game_to_opengl_draw_list.append(imagethree_opengl_container);

    //Image "Keyboard Button Q"
    game_to_opengl_image* keyboard_button_q = new game_to_opengl_image();
    keyboard_button_q->setup(QString(":/resources/keyboard buttons/q button.png"), 200, 250, 50, 50, 1);
    game_to_opengl* keyboard_button_q_opengl_container = new game_to_opengl();
    keyboard_button_q_opengl_container->containImage(keyboard_button_q);
    game_to_opengl_draw_list.append(keyboard_button_q_opengl_container);

    //Image "activated card"
    game_to_opengl_image* imagefour = new game_to_opengl_image();
    imagefour->setup(QString(":/resources/cards/activated-card-base-attack.png"), 170, 350, 100, 188, 1);
    game_to_opengl* imagefour_opengl_container = new game_to_opengl();
    imagefour_opengl_container->containImage(imagefour);
    game_to_opengl_draw_list.append(imagefour_opengl_container);


    canvas->sustain_image(game_to_opengl_draw_list);
    **/
}

//Relay key press and releases to the player input using keyboard class
void window_playAgainstAI::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Escape){ slotUserRequestingToCloseApplication(); }
    keyboardInput->key_event(event);
}
void window_playAgainstAI::keyReleaseEvent(QKeyEvent *event){ keyboardInput->key_event(event); }

//User Requesting to Close Card Game
void window_playAgainstAI::slotUserRequestingToCloseApplication()
{
    this->deleteLater();
}

//System is requesting another frame to be rendered
void window_playAgainstAI::slotUpdate()
{
    mouse_position = QCursor::pos();
    qint64 timesince = QDateTime::currentMSecsSinceEpoch() - timestamp_since_last_logic_cycle;
    if(timesince >= 2)
    {
        timestamp_since_last_logic_cycle = QDateTime::currentMSecsSinceEpoch();
        logic->game_update(mouse_position);
    }
    openglWidget->gpu_update();
}
