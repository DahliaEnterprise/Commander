#include "find.h"

find::find(QWidget *parent) : QWidget(parent)
{

}

void find::start()
{
    isCurrentlySearching = false;

    findFilterByFilename = new find_filterby_filename(nullptr);

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(mainLayout);

    filterBy = new QComboBox(nullptr);
    filterBy->addItem(QString("Filename"), QVariant(QString("filename")));
    mainLayout->addWidget(filterBy);

    wildcard = new QLineEdit(); wildcard->setPlaceholderText(QString("Wildcard"));
    mainLayout->addWidget(wildcard);

    searchInput = new QLineEdit(); searchInput->setPlaceholderText(QString("Search"));
    mainLayout->addWidget(searchInput);

    directoryFilter = new QTextEdit(); directoryFilter->setPlaceholderText(QString("Directory Filter\n/home/"));
    mainLayout->addWidget(directoryFilter);

    beginSearch = new QPushButton(QString("Begin Search"), nullptr);
    mainLayout->addWidget(beginSearch);

    QObject::connect(beginSearch, SIGNAL(clicked()), this, SLOT(operator_requesting_to_begin_search()));
}

void find::operator_requesting_to_begin_search()
{
    //Lock(disable) search inputs.
    filterBy->setDisabled(true);
    wildcard->setDisabled(true);
    searchInput->setDisabled(true);
    directoryFilter->setDisabled(true);
    beginSearch->setDisabled(true);

    findFilterByFilename->show();
    findFilterByFilename->start(wildcard->text(), searchInput->text(), directoryFilter->toPlainText());
}
