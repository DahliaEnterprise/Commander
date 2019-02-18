#ifndef THREAD_FIND_FILTERBY_FILENAME_H
#define THREAD_FIND_FILTERBY_FILENAME_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QList>
#include <QFileInfo>
#include <QDirIterator>
class thread_find_filterby_filename : public QObject
{
    Q_OBJECT
public:
    explicit thread_find_filterby_filename(QObject *parent = nullptr);
    void start();
    void do_search(QString wildcard, QString searchCriteria, QString directoriesToSearch);

    qint32 get_totalFilesSearched();
    qint32 get_totalFilesToSearch();
    QStringList get_searchResultList();

private:
    QString wildcard;
    QString searchCriteria;
    QString directoriesToSearch;

    int currentStatus;//0 = not started; 1 = determining amount of files to search through; 2 = total files determined now searching; 3= finished search;
    qint32 totalFilesToSearch;
    qint32 totalFilesSearched;
    QStringList searchResultList;

    void determine_total_files_to_search(QString directoriesToSearch);
    void produce_filtered_list(QString wildcard, QString searchCriteria, QString directoriesToSearch);
    bool filenameContainsMatch(QString wildcard, QString searchCriteria, QString filename);


signals:
    void commit_do_search();
    void finished();

public slots:

private slots:
    void slot_do_search();
};

#endif // THREAD_FIND_FILTERBY_FILENAME_H
