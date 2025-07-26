#include <iostream>
#include <ctime>

#include "function.h"

int main(int argc, char *argv[]) {
    // Вводим имя пользователя
    const std::string userName{enterUserName()};
    // Генерируем случайное число
    const int intendedNumber{numberGenerator()};
    display("Загадано число:", intendedNumber);
    // Настраиваем количество попыток
    int attempts{1}; // Счетчик попыток
    const int maxAttempts{5}; // Максимальное количество попыток
    display("Maximum number of attempts:", maxAttempts);

    // Основной игровой цикл
    // Проверяем, угадал ли пользователь число
    // или исчерпал ли он лимит попыток
    // Если угадал, то завершаем цикл
    // Если исчерпал лимит, то завершаем цикл
    bool win{false};
    while (attempts < maxAttempts && !win) {
        display("Attempt number", attempts);
        win = checkingNumber(intendedNumber, enterNumber(), attempts);
    }

    // Выводим результат игры
    // Если пользователь угадал число, то сохраняем результат в файл
    // Если пользователь исчерпал лимит попыток, то выводим сообщение об этом
    // и показываем загаданное число
    // В любом случае выводим таблицу рекордов
    const std::string logFileName{"game_results.txt"};
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
    display("\nHigh scores table:");
    viewLog(logFileName);    
     
    return 0;
}
