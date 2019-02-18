#ifndef FIND_FILTERBY_FILENAME_H
#define FIND_FILTERBY_FILENAME_H

#include <QWidget>
#include <QBoxLayout>
#include <QThread>
#include <QTimer>
#include <QProgressBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QProcess>
#include "find/thread_find_filterby_filename.h"
class find_filterby_filename : public QWidget
{
    Q_OBJECT
public:
    explicit find_filterby_filename(QWidget *parent = nullptr);
    void start(QString wildcard, QString searchCriteria, QString directoriesToSearch);

private:
    QBoxLayout* layout;
    QProgressBar* progressBar;
    QListWidget* listWidget;

    QTimer* thread_find_status_timer;
    QThread thread_find;
    thread_find_filterby_filename* thread_findFilterByFilename;

signals:

public slots:
    void slotFinished();
    void slotFindStatus_timeout();
    void slotShowInFileManager();
};

#endif // FIND_FILTERBY_FILENAME_H
