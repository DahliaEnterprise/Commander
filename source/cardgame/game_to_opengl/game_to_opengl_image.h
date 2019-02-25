#ifndef GAME_TO_OPENGL_IMAGE_H
#define GAME_TO_OPENGL_IMAGE_H

#include <QObject>
#include <QPainter>

class game_to_opengl_image : public QObject
{
    Q_OBJECT
public:
    explicit game_to_opengl_image(QObject *parent = nullptr);
    void setup(QString filename, int x, int y, int width, int height, int scale);
    void paint(QPainter* paint);

private:
    QString filename;
    int x;
    int y;
    int width;
    int height;
    int scale;
    QImage image;

signals:

public slots:
};

#endif // GAME_TO_OPENGL_IMAGE_H
