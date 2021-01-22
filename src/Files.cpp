//
//  Files.cpp
//  test
//
//  Created by RAIDEMOT on 21.01.2021.
//

#include "Files.hpp"

Files::Files(){}

// Вывести список инициализированных файлов
void Files::printInitFile()
{
    for(int i = 0; i < pathFiles.size(); i++)
    {
        std::cout << i << ") "<< pathFiles[i].first << " → \"" << pathFiles[i].second << "\"\n";
    }
}

// Список файлов для дальнейших манипуляций
void Files::setPathFile(std::string nameFile, std::string path)
{
    pathFiles.push_back(make_pair(nameFile, path));
}

// Получить количество инициализированных файлов
int Files::getNumberFiles()
{
    return pathFiles.size();
}

// Скопировать из файла #2 в конец файла #1
bool Files::copyFiles(unsigned short indexFile2, unsigned short indexFile1)
{
    using namespace std;

    char* bufferTemp;

    TextBuffer bufferFile(pathFiles[indexFile2].second);
    bufferFile.deleteFirstLine();
    cout << bufferFile.getSize();

    // Запись в файл
    ofstream infile(pathFiles[indexFile1].second, std::ios::app);
    infile.is_open();
    infile << "\n";

    bufferTemp = bufferFile.getBuffer();
    
    for (int i = 0; i < bufferFile.getSize(); i++)
    {
        infile << bufferTemp[i];
    }

    infile.close();

    return true;
}
//

// Посчитать количество табуляций и пробелов в строке
int Files::countNumberTabsAndLine(const char* buffer)
{
    int pPosition;
    int count;
    
    for (; (buffer[pPosition] != '\n' && buffer[pPosition] != '\0'); pPosition++) {
        if (buffer[pPosition] == '\t' && buffer[pPosition] != ' ') {
            count++;
        }
    }
    
    return count;
}

void Files::printNameFileColumns(unsigned short indexFile)
{
    using namespace std;
    
    char* bufferFile;
    unsigned int bufferFileSize;
    
    char bufferTemp[256];
    int pPosition = 0;
    
    int i = 0;
    
//    bufferFile = readFileBuf(pathFiles[indexFile].second, 0, bufferFileSize);
    
    cout << countNumberTabsAndLine(bufferFile) << endl;
//
//    for(int i = 0; i < countNumberTabsAndLine(bufferFile); i++)
//    {
//
//        sscanf(bufferFile, "%s", bufferTemp);
//
//        cout << i << ") " << bufferTemp << endl;
//    }
    
    while (sscanf(bufferFile, "%s", bufferTemp) == 1)
    {
        cout << i << ") " << bufferTemp << endl;
        i++;
    }
    
    
    
    delete[] bufferFile;
    bufferFile = nullptr;
    
};
