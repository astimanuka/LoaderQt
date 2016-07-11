#include "progressbar.h"

ProgressBar::~ProgressBar() {
    subject->unsubscribe();
}

ProgressBar::ProgressBar(FileLoader *s) : subject(s),actualCounter(0) {
    subject->subscribe(this);
}
void ProgressBar::display(){//todo this is just for testin the list and printing the objects inside it
    for (auto itr = progressFiles.begin(); itr != progressFiles.end(); itr++)
        cout << "path : " << (*itr).getPath() << " - size : " << (*itr).getFileSize() << endl;
}

int ProgressBar::getTotalSize(){
    int totalSize = 0;
    for (auto it = progressFiles.begin(); it != progressFiles.end(); it++)
        totalSize += (*it).getFileSize();
    return totalSize;
}

void ProgressBar::addFiles(Files file) {
    progressFiles.push_back(file);

}
