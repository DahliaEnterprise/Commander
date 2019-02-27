#include "playerinput_usingkeyboard.h"

playerInput_usingKeyboard::playerInput_usingKeyboard(QObject *parent) : QObject(parent)
{

}

void playerInput_usingKeyboard::key_event(QKeyEvent* event)
{
    //Keypress Q
    if(event->key() == Qt::Key_Q)
    {
        if(QEvent::KeyPress == event->type()){ lowercase_q_down = true; }
        else if(QEvent::KeyRelease == event->type()){ lowercase_q_down = false; }
    }
}
