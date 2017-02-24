#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <array>
using namespace std;


// Answers to questions
// 1
// a. What is stored in “matches”?

// b. What does “\d” mean?
		// digits


// int main(){
// 	regex pattern{R"(\d\d)"};
// 	string to_search = "I would like the number 98 to be found and printed, thanks.";
// 	smatch matches;
// 	regex_search(to_search, matches, pattern);
// 	for (auto match : matches){
// 		cout << match << endl;
// 	}
// 	return 0;
// }

// int main(){
// 	regex pattern{R"(<title>([\s\S]+)</title>)"};
// 	string to_search = "<html><head>Wow such header<title>This is a title</title>So top</head>Much body</html>";
// 	smatch matches;
// 	regex_search(to_search, matches, pattern);
// 	cout << matches[0] << endl;
// 	cout << matches[1] << endl;
// 	return 0;
// }

// int main(int argc, char const *argv[]) {
// 	// regex pattern{R"(>([\s\S]+)</a>)"};
//
// 	regex pattern{R"(\s*<([A-Z][A-Z0-9]*)\b[^>]*>(.*?)</\1>\s*)"};
// 	std::ifstream afile("stroustrup.txt", std::ios::in);
// 	string to_search;
//
// 	if (afile.is_open()) {
// 		std::string line;
// 		while (std::getline(afile, line)) {
// 			// std::cout << line << '\n';
// 			to_search.append(line);
// 		}
// 		afile.close();
// 	}
// 	else {
// 		std::cerr << "Unable to open file\n";
// 	}
//
// 	smatch matches;
// 	regex_search(to_search, matches, pattern);
//
// 	for (int i = 0; i < sizeof(matches); i++) {
// 		cout << matches[i] << endl;
// 	}
//
//
// 	return 0;
// }
int main()
{
    const std::regex re( R"(\s*<([A-Z][A-Z0-9]*)\b[^>]*>(.*?)</\1>\s*)", std::regex::icase ) ;
    // std::regex::icase - ignore case
    // \s* - zero or more whitespace characters
    // /\1 - backreference to first sub-match (subexpression within parantheses)
    // .*? - non-greedy match of zero or more characters (the ? specifies non-greedy match)

    const std::string lines[] =
    { "<name>venros</name>", "<posts>47</posts>", "  <topic>C++ Regex -Reading HTML Tags</topic>  " } ;

    for( const std::string& str : lines )
    {
        std::smatch results ;
        if( std::regex_match( str, results, re ) )
        {
            std::cout << "tag: '" << results[1] // first sub-match - for ([A-Z][A-Z0-9]*)
                      << "'\tvalue: '" << results[2] // second sub-match - for (.*?)
                      << "'\n" ;
        }
    }
}
