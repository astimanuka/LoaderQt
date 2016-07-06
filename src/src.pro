
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = LoaderQt

SOURCES += main.cpp \
    mainwindow.cpp \
    files.cpp

HEADERS += \
    mainwindow.h \
    files.h

FORMS += \
    mainwindow.ui
