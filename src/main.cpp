#include <iostream>
#include <ctime>

#include "function.h"

int main(int argc, char *argv[]) {
    // лучше использовать какую-то библиотеку для работы с аргументами командной строки
    // но для домашки будем использовать стандартные средства
    int maxValue{100}; // значение по умолчанию
    int maxAttempts{10}; // Максимальное количество попыток
    const std::string logFileName{"game_results.txt"};
    // display("argc =", argc);
    for (size_t i = 0; i < argc; i++){
        // display(std::to_string(i) + ": " + argv[i]);
        if (argv[i] == std::string{"--max"} && argv[i + 1]) { // i+1 - потенциальная ошибка, на компилятор вроде съел. 
            // проверять лениво для домашки сойдет :) runtime errora нет как не странно
            // если есть аргумент --max, то используем его значение
            // в качестве максимального значения для генерации случайного числа
            maxValue = std::stoi(argv[i + 1]);
        }
        if (argv[i] == std::string{"--table"}) {
            viewLog(logFileName);
            return 0;
        }
        if (argv[i] == std::string{"--level"} && argv[i + 1]) {
            // если есть аргумент --level, то используем его значение
            // в качестве уровня сложности игры
            // 1 - легкий, 2 - средний, 3 - сложный
            const int level{std::stoi(argv[i + 1])};
            setLevel(maxValue, maxAttempts, level);
        }
    }

    // Вводим имя пользователя
    const std::string userName{enterUserName()};
    // Генерируем случайное число
    const int intendedNumber{numberGenerator(maxValue)};
    display("Загадано число:", intendedNumber); // для отладки, в реальной игре не показываем загаданное число
    // Настраиваем количество попыток
    int attempts{1}; // Счетчик попыток
    display("Maximum number of attempts:", maxAttempts);

    // Основной игровой цикл
    // Проверяем, угадал ли пользователь число
    // или исчерпал ли он лимит попыток
    // Если угадал, то завершаем цикл
    // Если исчерпал лимит, то завершаем цикл
    bool win{false};
    while (attempts < maxAttempts && !win) {
        win = checkingNumber(intendedNumber, enterNumber(), attempts);
    }

    // Выводим результат игры
    // Если пользователь угадал число, то сохраняем результат в файл
    // Если пользователь исчерпал лимит попыток, то выводим сообщение об этом
    // и показываем загаданное число
    // В любом случае выводим таблицу рекордов

    if (win) {
        display("Congratulations, " + 
                userName + 
                "! You guessed the number in " + 
                std::to_string(attempts) + 
                " attempts.");
        saveToFile(logFileName, userName, attempts);
    } else {
        display("Sorry, " + 
                userName + 
                ". You've used all your attempts. The number was: ",  
                intendedNumber);
    }
    // Показываем таблицу рекордов
    viewLog(logFileName);    
     
    return 0;
}
