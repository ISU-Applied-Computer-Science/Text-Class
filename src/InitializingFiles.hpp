//
//  InitializingFiles.hpp
//  test
//
//  Created by RAIDEMOT on 21.01.2021.
//

#ifndef InitializingFiles_hpp
#define InitializingFiles_hpp

#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Files.hpp"

class InitializingFiles
{
public:
    InitializingFiles();
    InitializingFiles(Files* files, std::string filePath);
    bool openFile(Files* files, std::string filePath);
};

#endif /* InitializingFiles_hpp */
