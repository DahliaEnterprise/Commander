#include "thread_find_filterby_filename.h"

thread_find_filterby_filename::thread_find_filterby_filename(QObject *parent) : QObject(parent)
{
    currentStatus = 0;
    totalFilesSearched = 0;
    totalFilesToSearch = 0;
}

void thread_find_filterby_filename::start()
{
    QObject::connect(this, SIGNAL(commit_do_search()), this, SLOT(slot_do_search()));
}

void thread_find_filterby_filename::do_search(QString set_wildcard, QString set_searchCriteria, QString set_directoriesToSearch)
{
    wildcard.clear();wildcard.append(set_wildcard);
    searchCriteria.clear();searchCriteria.append(set_searchCriteria);
    directoriesToSearch.clear();directoriesToSearch.append(set_directoriesToSearch);

    //Disconnect "do_search()" from the calling thread.
    emit commit_do_search();
}

void thread_find_filterby_filename::slot_do_search()
{
    //Determine the total number of files that will be filtered.
    currentStatus = 1;
    determine_total_files_to_search(directoriesToSearch);
    currentStatus = 2;
    produce_filtered_list(wildcard, searchCriteria, directoriesToSearch);
    currentStatus = 3;
    emit finished();
}

void thread_find_filterby_filename::determine_total_files_to_search(QString directoriesToSearch)
{
    //split "string of character" by new lines.
    QStringList list_of_directories_to_search = directoriesToSearch.split("\n");
    for(int i = 0; i <  list_of_directories_to_search.size(); i++)
    {
        QDirIterator dirIterator(list_of_directories_to_search.at(i), QDirIterator::Subdirectories);
        while(dirIterator.hasNext())
        {
            dirIterator.next();//iterator points before the first directory so next() goes before any code using the iterator.
            if(dirIterator.fileInfo().isFile() == true){ totalFilesToSearch++; }
        }
    }
}


void thread_find_filterby_filename::produce_filtered_list(QString wildcard, QString searchCriteria, QString directoriesToSearch)
{
    searchResultList.clear();

    //split "string of character" by new lines.
    QStringList list_of_directories_to_search = directoriesToSearch.split("\n");
    for(int i = 0; i <  list_of_directories_to_search.size(); i++)
    {
        QDirIterator dirIterator(list_of_directories_to_search.at(i), QDirIterator::Subdirectories);
        while(dirIterator.hasNext())
        {
            dirIterator.next();//iterator points before the first directory so next() goes before any code using the iterator.
            if(dirIterator.fileInfo().isFile() == true)
            {
                totalFilesSearched++;

                bool fileName_contains_match = filenameContainsMatch(wildcard, searchCriteria, dirIterator.fileInfo().fileName());
                if(fileName_contains_match == true)
                {
                    searchResultList.append(dirIterator.fileInfo().absoluteFilePath());
                }
            }
        }
    }
}

bool thread_find_filterby_filename::filenameContainsMatch(QString wildcard, QString searchCriteria, QString filename)
{
    bool output = false;

    bool matchFound = false;

    bool wildcardUsed = false;
    if(wildcard.length() > 0){ wildcardUsed = true; }

    if(wildcardUsed == true)
    {

    }else if(wildcardUsed == false)
    {
        //No wildcard used, exact search is being requested.
        if(searchCriteria.compare(filename) == 0){ matchFound = true; }
    }

    output = matchFound;
    return output;
}

qint32 thread_find_filterby_filename::get_totalFilesSearched(){ return totalFilesSearched; }
qint32 thread_find_filterby_filename::get_totalFilesToSearch(){ return totalFilesToSearch; }
QStringList thread_find_filterby_filename::get_searchResultList(){ return searchResultList; }
