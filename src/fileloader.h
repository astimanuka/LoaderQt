#ifndef FILELOADER_H
#define FILELOADER_H



#include <list>
#include<vector>
#include "subject.h"
#include "observer.h"
#include "files.h"

class FileLoader : public Subject {

public:
    FileLoader() : totalSize(0), fileCounter(0) { }

    void putFiles(Files files) {
        fileList.push_back(files);
        //tmp = files;
        fileCounter++;
        //notify();//disabled cause it will be used the upload button
        //observer->update(files);
    }

    int getFileCounter() {
        return fileCounter;
    }

    void display() {
        for (auto itr = fileList.begin(); itr != fileList.end(); itr++)
            cout << "path : " << (*itr).getPath() << " - size : " << (*itr).getFileSize() << endl;
    }//todo should add another class that displays this function

    Files getLastFile() {
        return fileList.back();
    }

    int getTotalFileSize() {

        totalFilesSize(); //call the calculator of file sizes

        return totalSize;
    }

  //  void uploadObserver(){
    //       for(auto it=fileList.begin();it!=fileList.end();it++){//to be reviewed
      //         observer->update(*it);
        //   }
       //}

    Files getFileInPosition(int position){
        return fileList[position];
    }


    //---------- Functions ovverided from the subject class -------------


    virtual void subscribe(Observer *obs) override {
        observer = obs;
    }

    virtual void unsubscribe() override {
        observer = nullptr;
    }

    virtual void notify() override { // this causes an error
        observer->update(getLastFile());

    }

private:

    void totalFilesSize() {
        for (auto it = fileList.begin(); it != fileList.end(); it++)
            totalSize += (*it).getFileSize();
    }

private:
    //Files tmp;
    int totalSize;
    int fileCounter;
    Observer *observer;
    vector <Files> fileList;


};


#endif // FILELOADER_H
