#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QStringList>
#include"files.h"
#include"progressbar.h"
#include"fileloader.h"
#include <iostream>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();

    void on_uploadButton_clicked();


private:
    void browseButtonClick();
    void uploadButtonClick();
private:
    FileLoader *myFileLoader;
    ProgressBar *myprogress;
    int checkedUpload;
    int checkedBrowse;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
