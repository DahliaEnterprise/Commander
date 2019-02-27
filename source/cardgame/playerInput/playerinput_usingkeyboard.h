#ifndef PLAYERINPUT_USINGKEYBOARD_H
#define PLAYERINPUT_USINGKEYBOARD_H

#include <QObject>
#include <QKeyEvent>
#include <QDebug>
#include <QEvent>
class playerInput_usingKeyboard : public QObject
{
    Q_OBJECT
public:
    explicit playerInput_usingKeyboard(QObject *parent = nullptr);
    void key_event(QKeyEvent* event);

private:
    bool lowercase_q_down = false;

signals:

};

#endif // PLAYERINPUT_USINGKEYBOARD_H
