#ifndef MAINMENU_LOADINGGIZMO_H
#define MAINMENU_LOADINGGIZMO_H

#include <QObject>

class mainmenu_loadinggizmo : public QObject
{
    Q_OBJECT
public:
    explicit mainmenu_loadinggizmo(QObject *parent = nullptr);
    void start();

signals:

public slots:
};

#endif // MAINMENU_LOADINGGIZMO_H
