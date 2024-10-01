#include <iostream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include "TestScurt.h"
#include "TestExtins.h"

int main(){
    testAll();
    testAllExtins();
    _CrtDumpMemoryLeaks();
    std::cout<<"Finished Tests!"<<std::endl;
}
