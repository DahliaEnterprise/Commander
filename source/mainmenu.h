#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "find.h"

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

    //Applications
    class find* gui_find;

signals:

public slots:

private slots:
    void show_find_window();
};

#endif // MAINMENU_H
