#include "function.h"

#include <iostream>

void display(const std::string &msg) {
    std::cout << msg << std::endl;
}

void display(const std::string &msg, const int value) {
    std::cout << msg << " " << value << std::endl;
}

int enterNumber() {
    std::cout << "Enter your guess: ";  
    int value;
    std::cin >> value;
    return value;
}

int numberGenerator() {
    const int maxValue{100};
    std::srand(std::time(nullptr));
    return std::rand() % maxValue;
}

std::string enterUserName() {
    std::cout << "Hi! Enter your name, please: ";
    std::string userName{};
    std::cin >> userName;
    return userName;
}

bool checkingNumber(const int intendedNumber, const int numberToCheck) {
    static int att{0};
    att++;
    std::cout << "att: " << att << std::endl;
    bool result{false};
    if (intendedNumber < numberToCheck) {
        display("less than ", numberToCheck);
    }
    if (intendedNumber > numberToCheck) {
        display("less than ", numberToCheck);
    }
    if (intendedNumber == numberToCheck) {
        display("you win! attempts =", numberToCheck);
        result = true;
    }
    return result;
}
