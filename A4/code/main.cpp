// CSCE 222 - 506
// Name:     Joseph Martinsen
// Username: josephmart
// Email:    josephmart@tamu.edu

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

int main() {
    // Part 3
    std::cout << "Part 3" << '\n';
    regex pattern5{R"(\d\d)"};
    regex pattern6{R"(thanks)"};
    string to_search0 = "I would like the number 98"
              " to be found and printed, thanks.";
    smatch matches5;
    smatch matches6;
    regex_search(to_search0, matches5, pattern5);
    for (auto match : matches5) {
        cout << match << endl;
    }

    regex_search(to_search0, matches6, pattern6);
    for (auto match : matches6) {
      cout << match << endl;
    }

    std::cout << "\n\n";
    // Part 4
    std::cout << "Part 4" << '\n';
    regex pattern{R"(<head>([\s\S]+)<title>)"};
    regex pattern1{R"(</title>([\s\S]+)</head>)"};
    string to_search = "<html><head>Wow such a header <title>This is a title</title>"
                    "So top</head>Much body</html>";
    smatch matches0;
    smatch matches1;
    regex_search(to_search, matches0, pattern);
    cout << matches0[1] << endl;
    regex_search(to_search, matches1, pattern1);
    cout << matches1[1] << endl;


    std::cout << "\n\n";

    // Part 5
    std::cout << "Part 5" << '\n';
    std::ifstream afile("../stroustrup.txt", std::ios::in);
    std::string allData;

    if (afile.is_open()) {
       std::string line;
       while (std::getline(afile, line)) {
            allData += line;
            allData += '\n';
       }
       afile.close();
   }
   else {
       std::cerr << "Unable to open file\n";
   }

   regex pattern2{R"(<a href=\"(.*?.ppt)\")"};
   smatch matches2;

   // Shoutout to StackOverflow
   std::string::const_iterator searchStart(allData.cbegin());
   while(regex_search(searchStart, allData.cend(), matches2, pattern2))
    {
        std::cout << ( searchStart == allData.cbegin() ? "" : "\n" ) << matches2[1];
        searchStart += matches2.position() + matches2.length();
    }
    std::cout << '\n' << '\n';
}
