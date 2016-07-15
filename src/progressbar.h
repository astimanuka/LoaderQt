#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H


#include "observer.h"
#include "files.h"
#include "fileloader.h"
#include <QProgressBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QLabel>
#include <QString>

class ProgressBar : public Observer  {

public:
    ProgressBar(FileLoader *s);

    ~ProgressBar();

    void display() ;

    int getTotalSize() ;

    void updateProgressValue();

// overrided functions from the Observer class

    void update(Files file)override{
        addFiles(file);
    }

private:
    void addFiles(Files file);

private:
    FileLoader* subject;
    float actualCounter;
    QProgressBar* progressBar;
    QVBoxLayout* layout;
    QTextBrowser* textBrowser;
    QLabel* textLabel;
    QWidget* wrapper;
    list <Files> progressFiles;

};

#endif // PROGRESSBAR_H
