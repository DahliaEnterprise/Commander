#include "database_card.h"

database_card::database_card(QObject *parent) : QObject(parent)
{
    cardImageIsSet = false;
}

void database_card::loadCardInformation(QByteArray cardInformation)
{
    QString cardInformationString = QString::fromUtf8(cardInformation);
    cardInformationString.replace("\r", "");
    QStringList cardList = cardInformationString.split("\n");
    QStringList::const_iterator iterator = cardList.constBegin();
    while(iterator != cardList.constEnd())
    {
        QString keyvalueString = *iterator;
        if(keyvalueString.length() > 0)
        {
            QStringList keyvalue = keyvalueString.split(":");
            if(keyvalue.length() == 2)
            {
                QString key = keyvalue.at(0);
                QString value = keyvalue.at(1);
                if(key.compare("name") == 0){ name.clear(); name.append(value); }
                if(key.compare("type") == 0){ type.clear(); type.append(value); }
                if(key.compare("image") == 0){ image.clear(); image.append(value); }
                if(key.compare("fight") == 0){ fight = value.toInt(nullptr, 10); }
                if(key.compare("focus") == 0){ focus = value.toInt(nullptr, 10); }
                if(key.compare("agility") == 0){ agility = value.toInt(nullptr, 10); }
                if(key.compare("topspeed") == 0){ topspeed = value.toInt(nullptr, 10); }
                if(key.compare("moduspraeceptum") == 0){ moduspraeceptum.append(value); }
            }
        }
        iterator++;
    }
}

QImage database_card::get_image()
{
    if(cardImageIsSet == false)
    {
        cardImage = QImage(image);
        cardImageIsSet = true;
    }
    return cardImage;
}
