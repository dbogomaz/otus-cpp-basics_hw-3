#include "function.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

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
    // захотелось хранить записи отсортированными
    // Структура для хранения записей
    using Record = std::tuple<std::string, int>;
    std::vector<Record> records;

    // Чтение существующих данных
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string name;
        int att;
        while (inFile >> name >> att) {
            records.emplace_back(name, att);
        }
        inFile.close();
    }

    // Добавление новой записи
    records.emplace_back(userName, attempts);

    // Сортировка: сначала по попыткам, потом по имени
    std::sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        if (std::get<1>(a) != std::get<1>(b))
            return std::get<1>(a) < std::get<1>(b);
        return std::get<0>(a) < std::get<0>(b);
    });

    // Сохранение обратно в файл
    std::ofstream outFile(fileName, std::ios::trunc);
    if (outFile.is_open()) {
        for (const auto &rec : records) {
            outFile << std::get<0>(rec) << " " << std::get<1>(rec) << std::endl;
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
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}
