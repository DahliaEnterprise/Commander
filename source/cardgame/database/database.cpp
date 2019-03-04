#include "database.h"

database::database(QObject *parent) : QObject(parent)
{

}

void database::start()
{
    turnActivatedCards.clear();

    cardsdb = new QFile();
    cardsdb->setFileName(QString("C:\\Users\\Shane Betz\\Downloads\\Commander-master\\source\\resources\\db\\cards\\cardsmanifest.txt"));
    bool dbOpened = cardsdb->open(QIODevice::ReadWrite);
    if(dbOpened == true){
        QStringList cardsList = QString::fromUtf8(cardsdb->readAll()).split("\n");
        QStringList::const_iterator iterator = cardsList.constBegin();
        while(iterator != cardsList.constEnd())
        {
            QString cardFilename = *iterator;
            cardFile = new QFile();
            cardFile->setFileName(QString("C:\\Users\\Shane Betz\\Downloads\\Commander-master\\source\\resources\\db\\cards\\%1").arg(cardFilename));
            bool cardOpened = cardFile->open(QIODevice::ReadWrite);
            if(cardOpened == true)
            {
                QByteArray cardInformation = cardFile->readAll();
                database_card* dbcard = new database_card();
                dbcard->loadCardInformation(cardInformation);
                turnActivatedCards.append(dbcard);
            }
            cardFile->close();
            delete cardFile;
            iterator++;
        }
    }
    cardsdb->close();
    delete cardsdb;
}
