#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myFileLoader=new FileLoader();
    myprogress=new ProgressBar(myFileLoader);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QStringList filePath=QFileDialog::getOpenFileNames(this,tr("Chose a File"),"/home/","Source Files(*.cpp)");
    std::string myFilePath;

    for(QStringList::iterator it=filePath.begin();it!=filePath.end();it++){
        myFilePath=(*it).toUtf8().constData(); //this converts the qstring into a string
        Files files(myFilePath);
        myFileLoader->putFiles(files);
        ui->textBrowser->append(*it);
        std::cout<<"\nAdded file paths : \n"<<myFilePath<<" -- position :"<<myFileLoader->getFileCounter()<<std::endl;

    }
    int totalSize = myprogress->getTotalSize();
    QString totalSizeString=QString::number(totalSize);
    ui->totalFileSize->setText("Total files size : "+totalSizeString+" bytes");


}

void MainWindow::on_uploadButton_clicked()
{

    std::cout<<"\nProgress Bar Loading ..."<<std::endl;

    myprogress->display();

    myFileLoader->uploadObserver();
    ui->loadedFilesBrowser->append(QString::fromStdString(myprogress->getDisplay()));

}


