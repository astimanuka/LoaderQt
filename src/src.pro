
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = LoaderQt

SOURCES += main.cpp \
    mainwindow.cpp \
    files.cpp \
    subject.cpp \
    observer.cpp \
    progressbar.cpp \
    fileloader.cpp

HEADERS += \
    mainwindow.h \
    files.h \
    subject.h \
    observer.h \
    progressbar.h \
    fileloader.h

FORMS += \
    mainwindow.ui
