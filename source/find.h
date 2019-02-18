#ifndef FIND_H
#define FIND_H

#include <QWidget>
#include <QBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "find/find_filterby_filename.h"

class find : public QWidget
{
    Q_OBJECT
public:
    explicit find(QWidget *parent = nullptr);
    void start();

private:
    QBoxLayout* mainLayout;
    QComboBox* filterBy;
    QLineEdit* wildcard;
    QLineEdit* searchInput;
    QTextEdit* directoryFilter;
    QPushButton* beginSearch;

    bool isCurrentlySearching;

    find_filterby_filename* findFilterByFilename;

signals:

public slots:

private slots:
    void operator_requesting_to_begin_search();
};

#endif // FIND_H
