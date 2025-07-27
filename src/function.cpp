#include "function.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

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

int numberGenerator(const int maxValue) {
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

void saveToFile(const std::string &fileName, 
                const std::string &userName,
                const int attempts) {
    // Структура для хранения записей
    using Records = std::map<std::string, int>;
    Records records{};

    // Чтение существующих данных
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string name{};
        int att{};
        while (inFile >> name >> att) {
            records[name] = att ;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }

    // Добавление новой записи если игрок встречается первый раз или текущий результат лучше
    if (records.find(userName) == records.end() || 
        attempts < records[userName]) {
        records[userName] = attempts;
    }     

    // Сохранение обратно в файл
    std::ofstream outFile(fileName, std::ios::out | std::ios::trunc);
    if (outFile.is_open()) {
        for (const auto &rec : records) {
            outFile << rec.first << " " << rec.second << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void viewLog(const std::string &fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        display("\nHigh scores table:");
        while (std::getline(inFile, line)) {
            display(line);
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}
