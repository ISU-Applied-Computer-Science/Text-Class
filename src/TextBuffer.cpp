//
//  TextBuffer.cpp
//  test
//
//  Created by RAIDEMOT on 22.01.2021.
//

#include "TextBuffer.hpp"

TextBuffer::TextBuffer(std::string pathFile)
{
    this->pathFile = pathFile;
    createBuffer();
}

// Создать буфер из текстового файла
char* TextBuffer::createBuffer()
{
    using namespace std;
    
    ifstream in;
    in.open(pathFile, ios::binary);
    
    // Размер буфера
    size = in.seekg(0, ios::end).tellg();
    // Перемещение указателя в offset
    in.seekg(0);
    // Буфер с данными
    buffer = new char[size + 1];
    // Запись файла в буфер
    in.read(buffer, size);
    // Терминирующий ноль в конец буфера
    buffer[size] = '\0';
    
    in.close();
    
    return buffer;
}

// Переход на следующую строку
void TextBuffer::goToTheNextLine()
{
    for (; (buffer[pPosition] != '\n' && buffer[pPosition] != '\0'); pPosition++) {}

    if (buffer[pPosition] == '\n') {
        pPosition++;
    }
}

// Переход на предыдущую строку
void TextBuffer::goToThePreviousLine()
{
    for (; buffer[pPosition] != '\n'; pPosition--) {}

    if (buffer[pPosition] == '\n') {
        pPosition++;
    }
}

// Посчитать количество табуляций и пробелов в строке
int TextBuffer::countNumberTabsAndLine()
{
    int count;
    
    for (; (buffer[pPosition] != '\n' && buffer[pPosition] != '\0'); pPosition++) {
        if (buffer[pPosition] == '\t' && buffer[pPosition] != ' ') {
            count++;
        }
    }
    
    return count;
}

// Сброс указателя
void TextBuffer::resetPointer()
{
    pPosition = 0;
}

// Вывести весь текст
void TextBuffer::printAllText()
{
    std::cout << buffer << "\n";
}

void TextBuffer::deleteFirstLine()
{
    using namespace std;
    
    resetPointer();
    goToTheNextLine();
    
    ifstream in;
    in.open(pathFile, ios::binary);
    
    // Размер буфера
    size = in.seekg(pPosition, ios::end).tellg();
    
    // Перемещение указателя в offset
    in.seekg(pPosition);
    
    // Буфер с данными
    char* bufferTemp = new char[size + 1];
    // Запись файла в буфер
    in.read(bufferTemp, size);
    // Терминирующий ноль в конец буфера
    bufferTemp[size] = '\0';
    
    delete [] buffer;
    
    buffer = bufferTemp;
    
    delete [] bufferTemp;
    bufferTemp = nullptr;
    
    in.close();
    
}

// Получить буфер
char* TextBuffer::getBuffer()
{
    return buffer;
};


// Получить размер
int TextBuffer::getSize()
{
    return strlen(buffer);
}
