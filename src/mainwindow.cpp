#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myFileLoader=new FileLoader();
    myprogress=new ProgressBar(myFileLoader);
    checkedUpload=0;
    checkedBrowse=0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myFileLoader;
    delete myprogress;
}

void MainWindow::on_browseButton_clicked()
{

    std::cout<<"\nBrowse Files Loading ..."<<std::endl;
    if(!checkedBrowse)
        browseButtonClick();
    else
        QMessageBox::information(this,tr("Information"),"You have already browsed , please restart the program !",QMessageBox::Ok);

}

void MainWindow::browseButtonClick(){
    QStringList filePath=QFileDialog::getOpenFileNames(this,tr("Chose a File"),"$HOME/Desktop","Source Files(*.cpp)");
    std::string myFilePath;

    for(QStringList::iterator it=filePath.begin();it!=filePath.end();it++){
        myFilePath=(*it).toUtf8().constData(); //this converts the qstring into a string
        Files files(myFilePath);
        myFileLoader->putFiles(files);
        ui->textBrowser->append(*it);
        std::cout<<"added paths : "<< myFilePath<<" -- position :"<<myFileLoader->getFileCounter()<<std::endl;

    }
    int totalSize = myFileLoader->getTotalFileSize();
    QString totalSizeString=QString::number(totalSize);
    ui->totalFileSize->setText("Total files size : "+totalSizeString+" bytes");
    checkedBrowse++;

}


void MainWindow::on_uploadButton_clicked()
{
    std::cout<<"\nProgress Bar Loading ..."<<std::endl;
    if(!checkedUpload)
        uploadButtonClick();
    else
        QMessageBox::information(this,tr("Information"),"You have already loaded those files !",QMessageBox::Ok);
}

void MainWindow::uploadButtonClick(){

        float raportp=(float)100/myFileLoader->getFileCounter();
        float t=raportp;
        Files tmp("");
        for (int i=0;i<myFileLoader->getFileCounter();i++){
            tmp=myFileLoader->getFileInPosition(i);
            myprogress->update(tmp);
            ui->loadedFilesBrowser->append(QString::fromStdString(tmp.getPath()));
            std::cout<<"loaded path : "<<tmp.getPath()<<" - size : "<<tmp.getFileSize()<<std::endl;

            //this displays the progressbar
            ui->progressBar->setValue(t);
            t+=raportp;

            //this will display the loaded files size int bytes
            int totalSize = myprogress->getTotalSize();
            QString totalSizeString=QString::number(totalSize);
            ui->totalFileSizeLoaded->setText("Total loaded files : "+totalSizeString+" bytes");
        }
        checkedUpload++;


}


