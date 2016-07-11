#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H


#include "observer.h"
#include "files.h"
#include "fileloader.h"


class ProgressBar : public Observer {


public:
    ProgressBar(FileLoader *s);

    ~ProgressBar();

    void display() ;

    int getTotalSize() ;


    //---------------------overrided functions from the Observer class-----------------
    void update(Files file)override{
        addFiles(file);
    }

private:
    void addFiles(Files file);

private:
    FileLoader *subject;
    int actualCounter;
    list <Files> progressFiles;

};

#endif // PROGRESSBAR_H
