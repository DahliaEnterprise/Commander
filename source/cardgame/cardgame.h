#ifndef CARDGAME_H
#define CARDGAME_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QScreen>
#include <QSize>
#include <QDesktopWidget>
#include <QPushButton>

#include "cardgame/window_playagainstai.h"

class cardgame : public QWidget
{
    Q_OBJECT
public:
    explicit cardgame(QWidget *parent = nullptr);
    void start();

private:
    QBoxLayout* layout;
    QPushButton* button_configuration;
    QPushButton* button_playAgainstAI;
    QPushButton* button_playAgainstHuman;
    QLabel* label;

    window_playAgainstAI* playAgainstAI;

signals:

private slots:
    void show_playAgainstAI();
};

#endif // CARDGAME_H
