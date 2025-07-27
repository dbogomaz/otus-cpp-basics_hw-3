#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

/**
 * @brief Выводит сообщение на экран.
 * 
 * @param msg Сообщение для вывода.
 */
void display(const std::string &msg);

/**
 * @brief Выводит сообщение и числовое значение на экран.
 * 
 * @param msg Сообщение для вывода.
 * @param value Числовое значение для вывода.
 */
void display(const std::string &msg, const int value);

/**
 * @brief Запрашивает ввод числа у пользователя.
 * 
 * @return Введённое пользователем число.
 */
int enterNumber();

/**
 * @brief Генерирует случайное число.
 * 
 * @return Сгенерированное число.
 */
int numberGenerator(const int maxValue = 100);

/**
 * @brief Запрашивает ввод имени пользователя.
 * 
 * @return Введённое имя пользователя.
 */
std::string enterUserName();

/**
 * @brief Проверяет, совпадает ли переданное число с загаданным и обновляет количество попыток.
 * 
 * @param intendedNumber Загаданное число.
 * @param numberToCheck Проверяемое число.
 * @param attempts Ссылка на количество попыток; будет увеличено.
 * @return true если numberToCheck совпадает с intendedNumber, false в противном случае.
 */
bool checkingNumber(const int intendedNumber, 
                    const int numberToCheck,    
                    int &attempts);

/**
 * @brief Сохраняет данные в файл.
 * 
 * @param fileName Имя файла для сохранения.
 * @param data Данные для сохранения.
 * @param attempts Количество попыток.
 */
void saveToFile(const std::string &fileName, 
                const std::string &data,    
                const int attempts);

/**
 * @brief Просматривает содержимое файла журнала.
 * 
 * @param fileName Имя файла для просмотра.
 */
void viewLog(const std::string &fileName);

/**
 * @brief Устанавливает параметры уровня сложности игры.
 * 
 * @param[out] maxValue Ссылка на переменную, в которую будет записано максимальное загадываемое значение.
 * @param[out] maxAttempts Ссылка на переменную, в которую будет записано количество выделяемых попыток.
 * @param[in] level Уровень сложности (1 - легкий, 2 - средний, 3 - сложный). По умолчанию 1.
 */
void setLevel(int &maxValue, 
              int &maxAttempts, 
              const int level = 1);

#endif // FUNCTION_H