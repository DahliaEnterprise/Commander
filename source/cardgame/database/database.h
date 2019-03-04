#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QList>
#include "cardgame/database/database_card.h"
extern QByteArray database_openfile(QString directory_and_filename);

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    void start();

private:
    QFile* cardsdb;
    QFile* cardFile;

    QList<database_card*> turnActivatedCards;

signals:

public slots:
};

#endif // DATABASE_H
