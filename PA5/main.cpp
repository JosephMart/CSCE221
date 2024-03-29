#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>

#include "hash.h"

int main()
{

    std::string input_file = "input.csv";
    std::string roster_file = "roster.csv";
    std::ifstream ifile_input = std::ifstream(input_file);
    std::ifstream ifile_roster = std::ifstream(roster_file);
    std::ofstream output_file("output.csv", std::ios::out);
    std::string line;
    std::regex pattern = std::regex(R"(([\s\S]+),([\s\S]+),(\d{9}),(\d+))");
    std::regex pattern_roster = std::regex(R"(([\s\S]+),([\s\S]+),(\d{9}))");
    std::smatch match;
    std::smatch match_roster;

    hash HashTbl = hash();

    // Get Grades
    while(getline(ifile_input, line))
    {
        regex_search(line, match, pattern);
        std::stringstream ss(match[4]);
        int grade;
        ss >> grade;

        unsigned int uin = strtoul(match[3].str().c_str(), nullptr, 0);

        HashTbl.insert(uin, grade);
    }

    HashTbl.PrintTableInfo();

    while(getline(ifile_roster, line))
    {
        regex_search(line, match_roster, pattern_roster);
        unsigned int uin = strtoul(match_roster[3].str().c_str(), nullptr, 0);
        int grade = HashTbl.searchGrade(uin);

        output_file << line.substr(0,line.length()-1);

        if (grade != 0)
            output_file << grade;

        output_file << '\n';
    }
    output_file.close();
    return 0;
}
