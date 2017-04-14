#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>

#include "hash.h"

int main()
{

    std::string input_file = "input.csv";
    std::ifstream ifile_input = std::ifstream(input_file);
    std::string line;
    std::regex pattern = std::regex(R"(([\s\S]+),([\s\S]+),(\d{9}),(\d+))");
    std::smatch match;

    hash HashTbl = hash();

    // Get Grades
    while(getline(ifile_input, line))
    {
        regex_search(line, match, pattern);
        // std::cout << match[1] << '\n';
        // std::cout << match[2] << '\n';
        // std::cout << HashTbl.Hash() << '\n';
        // std::cout << match[4] << '\n';
        std::stringstream ss(match[4]);
        int grade;
        ss >> grade;

        unsigned int uin = strtoul(match[3].str().c_str(), nullptr, 0);

        HashTbl.insert(uin, grade);
    }
    HashTbl.PrintTable();



    return 0;
}
