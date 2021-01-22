//
//  Files.hpp
//  test
//
//  Created by RAIDEMOT on 21.01.2021.
//

#ifndef Files_hpp
#define Files_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "TextBuffer.hpp"

class Files
{
private:
    // Список путей
    std::vector <std::pair<std::string, std::string>> pathFiles;
    
    // Посчитать количество табуляций и пробелов в строке
    int countNumberTabsAndLine(const char* buffer);
    
public:
    Files();
    
    // Вывести список инициализированных файлов
    void printInitFile();
    
    // Список файлов для дальнейших манипуляций
    void setPathFile(std::string nameFile, std::string path);
    
    // Получить количество инициализированных файлов
    int getNumberFiles();
    
    // Скопировать из файла #2 в конец файла #1
    bool copyFiles(unsigned short indexFile2, unsigned short indexFile1);
    
    // Сортировка файла по возрастанию
    bool sortFileфAscending(unsigned short indexFile);
    
    // Вывести все столбцы из файла
    void printNameFileColumns(unsigned short indexFile);
    
};

#endif /* Files_hpp */
