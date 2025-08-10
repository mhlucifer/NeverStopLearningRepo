

#include <iostream>
#include<fstream>
#include"parser.h"

int main()
{
    std::ifstream log_file("log.txt");
    if (log_file.is_open())
    {
        std::cerr << "错误，无法打开文件" << std::endl;
        return 1;
    }
    std::string current_line;
    while(std::getline())

    
}

