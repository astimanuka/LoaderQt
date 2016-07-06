#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include"files.h"

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

    Files* myNewFile;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
