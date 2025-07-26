#include <iostream>
#include <ctime>

#include "function.h"

int main(int argc, char *argv[]) {

    const std::string userName{enterUserName()};

    const int intendedNumber{numberGenerator()};
    display("Загадано число:", intendedNumber);

    int attempts{0}; // Счетчик попыток
    const int maxAttempts{5}; // Максимальное количество попыток
    display("Maximum number of attempts:", maxAttempts);

    bool win{false};
    while (attempts < maxAttempts && !win) {
        display("Attempt number", attempts);
        win = checkingNumber(intendedNumber, enterNumber(), attempts);
    }

    if (win) {
        display("Congratulations, " + 
                userName + 
                "! You guessed the number in " + 
                std::to_string(attempts) + 
                " attempts.");
    } else {
        display("Sorry, " + 
                userName + 
                ". You've used all your attempts. The number was: ",  
                intendedNumber);
    }
     
    return 0;
}
