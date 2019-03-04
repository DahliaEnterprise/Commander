#ifndef DATABASE_CARD_H
#define DATABASE_CARD_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QImage>
class database_card : public QObject
{
    Q_OBJECT
public:
    explicit database_card(QObject *parent = nullptr);
    void loadCardInformation(QByteArray cardInformation);
    QImage get_image();

private:
    QString name;
    QString type;
    QString image;
    int fight;
    int focus;
    int agility;
    int topspeed;
    QStringList moduspraeceptum;
    bool cardImageIsSet;
    QImage cardImage;

signals:

public slots:
};

#endif // DATABASE_CARD_H
