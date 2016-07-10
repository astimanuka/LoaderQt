#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H


#include "observer.h"
#include "files.h"
#include "fileloader.h"


class ProgressBar : public Observer {


public:
    ProgressBar(FileLoader *s);

    ~ProgressBar();

    //this should be cancelled
    void progressBar(float size) {
        float progress = size;
        while (progress < 1.0) {
            int barWidth = 50;

            std::cout << "[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) std::cout << "=";
                else if (i == pos) std::cout << ">";
                else std::cout << " ";
            }
            std::cout << "] " << int(progress * 100.0) << " %\r";
            std::cout.flush();

            progress += 0.1; // for demonstration only
        }
        std::cout << std::endl;

        cout << endl << endl << " Operation completed successfully.\n" << flush;


    }

    void display() ;
    string getDisplay();

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
