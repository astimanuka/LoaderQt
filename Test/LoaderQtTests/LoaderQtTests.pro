CONFIG += console c++11

INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../../"


SOURCES += \
    maintests.cpp \
    gtest/src/gtest-typed-test.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-all.cc \
    gtest/src/gtest.cc \
    ../../src/files.cpp

HEADERS += \
    ../../src/files.h
