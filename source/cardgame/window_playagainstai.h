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
#include "playerInput/playerinput_usingkeyboard.h"
#include "cardgame/gamelogic/gamelogic.h"
class window_playAgainstAI : public QWidget
{
    Q_OBJECT
public:
    explicit window_playAgainstAI(QWidget *parent = nullptr);
    ~window_playAgainstAI();

    void start();

private:
    opengl_widget* openglWidget;
    opengl_canvas* canvas;
    QTimer* update_gpu_trigger;

    QBoxLayout* layout;

    playerInput_usingKeyboard* keyboardInput;
    gamelogic* logic;
    qint64 timestamp_since_last_logic_cycle;
    QPoint mouse_position;

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

signals:

public slots:
    void slotUserRequestingToCloseApplication();

private slots:
    void slotUpdate();

};

#endif // WINDOW_PLAYAGAINSTAI_H
