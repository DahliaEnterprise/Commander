#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "find.h"
#include "cardgame/cardgame.h"
class mainmenu : public QWidget
{
    Q_OBJECT
public:
    explicit mainmenu(QWidget *parent = nullptr);
    void start();

private:
    //Layout
    QBoxLayout* layout;
    QLabel* creator_image;

    QBoxLayout* panel_of_buttons_layout;
    QPushButton* button_find;
    QPushButton* button_cardgame;

    //Applications
    class find* gui_find;
    cardgame* gui_cardgame;


signals:

public slots:

private slots:
    void show_find_window();
    void show_cardgame_window();
};

#endif // MAINMENU_H
