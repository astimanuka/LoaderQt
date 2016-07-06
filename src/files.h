#ifndef FILES_H
#define FILES_H
#include<QFile>
#include<QString>

class Files
{
public:
    Files();
    void setPath(QString path);
    void setFile(QFile* file);
    QString getPath();
    QFile* getFile();
    //bool operator !=(string a, string b);

private:
    QFile *myFile;
    QString filePath;
};

#endif // FILES_H
