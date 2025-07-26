#include "function.h"

#include <iostream>
#include <fstream>

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

bool checkingNumber(const int intendedNumber, 
                    const int numberToCheck,
                    int &attempts) {
    static int att{0};
    att++;

    bool result{false};
    if (intendedNumber < numberToCheck) {
        display("less than ", numberToCheck);
    }
    if (intendedNumber > numberToCheck) {
        display("greater than ", numberToCheck);
    }
    if (intendedNumber == numberToCheck) {
        // display("you win! attempts =", att);
        result = true;
    }
    attempts = att;
    return result;
}

void saveToFile(const std::string &fileName, const std::string &data) {
    std::ofstream outFile(fileName, std::ios::app);
    if (outFile.is_open()) {
        outFile << data << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }   
}

void viewLog(const std::string &fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}
