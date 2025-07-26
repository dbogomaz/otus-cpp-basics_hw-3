#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

void display(const std::string &msg);
void display(const std::string &msg,const int value);
int enterNumber();
int numberGenerator();
std::string enterUserName();
bool checkingNumber(const int intendedNumber, 
                    const int numberToCheck,    
                    int &attempts);
void saveToFile(const std::string &fileName, const std::string &data);
void viewLog(const std::string &fileName);

#endif // FUNCTION_H