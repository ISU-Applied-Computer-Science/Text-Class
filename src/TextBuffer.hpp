//
//  TextBuffer.hpp
//  test
//
//  Created by RAIDEMOT on 22.01.2021.
//

#ifndef TextBuffer_hpp
#define TextBuffer_hpp

#include <string>
#include <fstream>
#include <cstring> 
#include <iostream>

class TextBuffer
{
private:
    // Буфер
    char* buffer;
    
    // Путь к файлу
    std::string pathFile;

    // Текущее расположение указатель
    int pPosition;
    
    // Создать буфер
    char* createBuffer();
    
    int size;
    
public:
    TextBuffer(std::string pathFile);
    
    // Получить текущий указатель
    int getCurrentPointer();
    
    // Получить буфер
    char* getBuffer();
    
    // Получить размер
    int getSize();
    
    // Сброс указателя
    void resetPointer();
    
    // Вывести весь текст
    void printAllText();
    
    // Переход на следующую строку
    void goToTheNextLine();
    
    // Удалить первую строку
    void deleteFirstLine();
    
    // Переход на предыдущую строку
    void goToThePreviousLine();
    
    // Посчитать количество табуляций и пробелов в строке
    int countNumberTabsAndLine();
};

#endif /* TextBuffer_hpp */
