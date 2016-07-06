#include "files.h"

Files::Files()
{

}

void Files::setPath(QString path){
    Files::filePath=path;
}
void Files::setFile(QFile* file){
    Files::myFile=file;
}
QString Files::getPath(){
    return Files::filePath;
}
QFile* Files::getFile(){
    return Files::myFile;
}
