#ifndef GAME_TO_OPENGL_IMAGE_H
#define GAME_TO_OPENGL_IMAGE_H

#include <QObject>
#include <QPainter>
#include <QTimer>

class game_to_opengl_image : public QObject
{
    Q_OBJECT
public:
    explicit game_to_opengl_image(QObject *parent = nullptr);
    void setup(QString setfilename, int setx, int sety, int setwidth, int setheight, int setscale);
    void setup(QPixmap image,int setx, int sety, int setwidth, int setheight, int setscale);
    void resetPixmap(QPixmap setpixmap);
    void updateCoordinates(double x, double y);
    void show(bool state);
    void paint(QPainter* paint);
    QRect get_bounding_box();

private:
    QString filename;
    double x;
    double y;
    int width;
    int height;
    int scale;
    QPixmap pixmap;
    QPixmap blankPixmap;
    QImage image;
    QTimer* tempTimer;

signals:

public slots:
};

#endif // GAME_TO_OPENGL_IMAGE_H
