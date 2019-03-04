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
    thread_db = new QThread();
    db = new database();
    db->moveToThread(thread_db);
    thread_db->start();
    db->start();

    //QApplication::setOverrideCursor(Qt::BlankCursor);

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
    logic = new gamelogic(db, canvas, nullptr);
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
    update_gpu_trigger->start(2);

    //Start mouse update cycle
    update_mouse_trigger = new QTimer();
    QObject::connect(update_mouse_trigger, SIGNAL(timeout()), this, SLOT(slotMousePositionUpdate()));
    update_mouse_trigger->start(10);
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
    qint64 timesince = QDateTime::currentMSecsSinceEpoch() - timestamp_since_last_logic_cycle;
    if(timesince >= 10)
    {
        timestamp_since_last_logic_cycle = QDateTime::currentMSecsSinceEpoch();
        logic->game_update(mouse_position);
    }
    openglWidget->gpu_update();
}

//Update mouse position
void window_playAgainstAI::slotMousePositionUpdate()
{
    mouse_position = QCursor::pos();
}

