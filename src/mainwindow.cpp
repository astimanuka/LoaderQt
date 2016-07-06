#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myNewFile= new Files;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
   // myNewFile= new Files;
    myNewFile->setPath(QFileDialog::getOpenFileName(this,tr("Chose a file"),"/home/","Source Files(*.cpp)"));
    myNewFile->setFile(new QFile(myNewFile->getPath()));
    ui->fileAddress->setText(myNewFile->getPath());
}

void MainWindow::on_uploadButton_clicked()
{
   if(myNewFile->getPath()!="\0"){
    if (!myNewFile->getFile()->open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",myNewFile->getFile()->errorString());

    QTextStream inputStr(myNewFile->getFile());
    QFileInfo* info=new QFileInfo(myNewFile->getPath());


     while(!inputStr.atEnd()){
        ui->textBrowser->setText(inputStr.readAll());
        for (int c=0;c<=100;c+=2)
            ui->progressBar->setValue(c);
        }
     ui->fileName->setText(info->completeBaseName()+"."+info->completeSuffix());
    }else
       QMessageBox::information(this,"info","Please choose a file",QMessageBox::Ok);
}
