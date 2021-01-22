//
//  Navigation.hpp
//  test
//
//  Created by RAIDEMOT on 21.01.2021.
//

#ifndef Navigation_hpp
#define Navigation_hpp

#include <string>
#include <iostream>

#include "Files.hpp"
#include "InitializingFiles.hpp"

class Navigation
{
private:
    unsigned short choice;
    Files *ptrFiles;
    
    // Модули //
    // Интерфейс копирование из файла #2 в конец файла #1
    void copyFiles();
    
    // Интерфейс Сортировка данных по возрастанию
    void sortFileфAscending();
    
public:
    Navigation();
    
    // Интерфейс инициализация файлов
    void openingFiles();
    
    // Интерфейс главного меню
    void mainMenu();
    
    
};

#endif /* Navigation_hpp */
