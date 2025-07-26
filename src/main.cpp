#include <iostream>
#include <ctime>

#include "function.h"

int main(int argc, char *argv[]) {

    const std::string userName{enterUserName()};
   
    display(userName);

    const int intendedNumber{numberGenerator()};
    display("Загадано число:", intendedNumber);

    while (!checkingNumber(intendedNumber, enterNumber()))
    {
        /* code */
    }
    
   
    
    return 0;
}
