#include<gtest/gtest.h>
#include "../../src/files.h"
#include <iostream>
using namespace std;


TEST(testFilesClass, testSetterAndGetter_1){

    //fexpected to fail
    Files* actual= new Files();
    actual->setPath("mypath");

    ASSERT_EQ("mypath",actual->getPath());

}
TEST(testFilesClass,testSetterAndGetterPath_1){

    Files* myfile= new Files();
    myfile->setPath("/home/astimanuka/Desktop/main.cpp");

    Files* myfile2= new Files();
    myfile2->setPath("/home/astimanuka/Desktop/main.cpp");

    ASSERT_EQ(myfile2->getPath(),myfile->getPath());
}



int main(int argc,char* argv[]){

    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

}
