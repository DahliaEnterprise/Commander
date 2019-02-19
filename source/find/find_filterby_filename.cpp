#include "find_filterby_filename.h"

find_filterby_filename::find_filterby_filename(QWidget *parent) : QWidget(parent)
{

}

void find_filterby_filename::start(QString wildcard, QString searchCriteria, QString directoriesToSearch)
{
    this->setWindowTitle("Determining amount of files to search");

    layout = new QBoxLayout(QBoxLayout::TopToBottom, nullptr);
    this->setLayout(layout);

    progressBar = new QProgressBar();
    progressBar->setRange(0, 100);
    progressBar->setStyleSheet(QString("QProgressBar:horizontal{ padding:10px; } "));
    layout->addWidget(progressBar);

    listWidget = new QListWidget();
    layout->addWidget(listWidget);
    QObject::connect(listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(slotShowInFileManager()));

    thread_findFilterByFilename = new thread_find_filterby_filename(nullptr);
    thread_findFilterByFilename->start();
    thread_findFilterByFilename->moveToThread(&thread_find);
    QObject::connect(thread_findFilterByFilename, SIGNAL(finished()), this, SLOT(slotFinished()));
    thread_find_status_timer = new QTimer();
    thread_find_status_timer->start(100);
    QObject::connect(thread_find_status_timer, SIGNAL(timeout()), this, SLOT(slotFindStatus_timeout()));
    thread_find.start();
    thread_findFilterByFilename->do_search(wildcard, searchCriteria, directoriesToSearch);
}

void find_filterby_filename::slotFinished()
{
    QStringList searchResultList = thread_findFilterByFilename->get_searchResultList();
    for(int i = 0; i < searchResultList.length(); i++)
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(searchResultList.at(i));
        listWidget->addItem(newItem);
    }
    this->setWindowTitle("Result of Searching");

    progressBar->hide();
}

void find_filterby_filename::slotFindStatus_timeout()
{
    double totalFiles_toSearch = QString("%1").arg(thread_findFilterByFilename->get_totalFilesToSearch()).toDouble();
    double totalFiles_searched = QString("%1").arg(thread_findFilterByFilename->get_totalFilesSearched()).toDouble();
    double progress_raw = totalFiles_searched / totalFiles_toSearch;
    double progress_percentage = progress_raw * 100;
    int progress_percentage_as_int = (int)progress_percentage;
    progressBar->setValue(progress_percentage_as_int);

    if(thread_findFilterByFilename->get_currentStatus() == 1)
    {
        this->setWindowTitle("Gathering Files");
    }else if(thread_findFilterByFilename->get_currentStatus() == 2)
    {
        this->setWindowTitle("Filtering Files");
    }else if(thread_findFilterByFilename->get_currentStatus() == 3)
    {
        this->setWindowTitle("Results Produced From Search");
    }
}

void find_filterby_filename::slotShowInFileManager()
{
    QList<QListWidgetItem*> selectedItems = listWidget->selectedItems();
    QListWidgetItem* item = selectedItems.at(0);
    QProcess* process = new QProcess(nullptr);
    process->startDetached(QString("xdg-open %1").arg(item->text()));
}
