#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <math.h>
#include <iomanip>
#include <string>

#define TAB 20

// Sources
// https://www.youtube.com/watch?v=keEcyZfrmxY

void readFile(std::vector<int>* v, std::string fileName);
void Binary_search_up(std::vector<int> v, int value);
void Binary_search_down(std::vector<int> v, int value);
void results(int value, int mid, int comp, bool found, std::vector<int> v);
void checkSort(std::vector<int> v);
template<typename T> void printD(T t, const int& width)
{
    std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
}

int main(int argc, char const *argv[]) {
	try{
		std::vector<int> v;
		int value = 0;

		// Inc Even
		readFile(&v, "up.txt");
		checkSort(v);
		std::cout << "Running comparisions for increasing 2^n values " << '\n';
		printD("Range",TAB);
		printD("Target",TAB);
		printD("Comps.",TAB);
		std::cout << '\n';

		for (int i = 0; i < 12; i++) {
			std::vector<int> temp;
			int value = pow(2,i);

			for (int j = 0; j < value; j++) {
				temp.push_back(v.at(j));
			}
			Binary_search_up(temp, value);
			temp.clear();
		}

		// Dec Even
		v.clear();
		readFile(&v, "down.txt");
		checkSort(v);
		std::cout << "\n\nRunning comparisions for decreasing 2^n values" << '\n';
		printD("Range",TAB);
		printD("Target",TAB);
		printD("Comps.",TAB);
		std::cout << '\n';

		for (int i = 0; i < 12; i++) {
			std::vector<int> temp;
			int value = pow(2,i);

			for (int i = v.size() - value; i < v.size(); i++) {
				temp.push_back(v.at(i));
			}

			Binary_search_down(temp, 1);
			temp.clear();
		}

		// Inc Odd
		v.clear();
		readFile(&v, "up.txt");
		checkSort(v);
		std::cout << "\n\nRunning comparisions for increasing 2^n - 1 values " << '\n';
		printD("Range",TAB);
		printD("Target",TAB);
		printD("Comps.",TAB);
		std::cout << '\n';

		for (int i = 1; i < 12; i++) {
			std::vector<int> temp;
			int value = pow(2,i) - 1;

			for (int j = 0; j < value; j++) {
				temp.push_back(v.at(j));
			}
			Binary_search_up(temp, value);
			temp.clear();
		}

		// Dec Odd
		v.clear();
		readFile(&v, "down.txt");
		checkSort(v);
		std::cout << "\n\nRunning comparisions for decreasing 2^n values" << '\n';
		printD("Range",TAB);
		printD("Target",TAB);
		printD("Comps.",TAB);
		std::cout << '\n';

		for (int i = 1; i < 12; i++) {
			std::vector<int> temp;
			int value = pow(2,i) - 1;

			for (int i = v.size() - value; i < v.size(); i++) {
				temp.push_back(v.at(i));
			}

			Binary_search_down(temp, 1);
			temp.clear();
		}

		return 0;
	}
	catch(std::runtime_error& e) {
		std::cerr << "ERROR: " << e.what() << 'n';
		return -1;
	}
}

void readFile(std::vector<int>* v, std::string fileName) {
	// Read file into a vector
	std::ifstream afile(fileName, std::ios::in);
	if (afile.is_open()) {
		std::string num;
		while (std::getline(afile, num, ',')) {
			v->push_back(atoi(num.c_str()));
		}
		afile.close();
	}
	else {
		throw std::runtime_error("Unable to open file");
	}
}

void results(int value, int mid, int comp, bool found, std::vector<int> v) {
	// Output resultant info
	std::cout << "\nSearching for: " << value << '\n';
	// std::cout << "in { ";
	// for (int i = 0; i < v.size(); i++) {
	// 	std::cout << v.at(i);
	// 	if (i != v.size() - 1) {
	// 		std::cout << ",";
	// 	}
	// 	std::cout << " ";
	// }
	// std::cout << "}" << '\n';

	if (found) {
		std::cout << "Found at index: " << mid << '\n';
		std::cout << "Number of comparisons: " << comp << '\n';
	} else {
		std::cout << "Not found" << '\n';
	}
}

void Binary_search_up(std::vector<int> v, int value) {
	// Binary Search
	int low = 0;
	int high = v.size()-1;
	int mid = 0;
	bool found = false;
	int comp = 0;
	std::string range = "[1, ";

	while (low <= high && !found) {
		mid = (low + high) / 2;
		if (v[mid] == value){
			found = true;
			comp++;
		} else if (v[mid] < value) {
			low = mid + 1;
			comp += 2;
		}
		else {
			high = mid - 1;
			comp += 2;
		}
	}
	// results(value, mid, comp, found, v);

	printD(range.append(std::to_string(value)).append("]"),TAB);
	printD(value,TAB);
	printD(comp,TAB);
	std::cout << '\n';

}

void Binary_search_down(std::vector<int> v, int value) {
	// Binary Search
	int low = 0;
	int high = v.size()-1;
	int mid = 0;
	bool found = false;
	int comp = 0;
	std::string range = "[1, ";

	while (low <= high && !found) {
		mid = (low + high) / 2;
		if (v[mid] == value){
			found = true;
			comp++;
		} else if (v[mid] > value) {
			low = mid + 1;
			comp += 2;
		}
		else {
			high = mid - 1;
			comp+=2;
		}
	}

	printD(range.append(std::to_string(v.size())).append("]"),TAB);
	printD(value,TAB);
	printD(comp,TAB);
	std::cout << '\n';
}

void checkSort(std::vector<int> v) {
	// Confrim that vector is sorted
	bool assend = true;
	bool dessend = true;

	for (int i = 1; i < v.size(); i++)
	{
		if (v.at(i-1) > v.at(i))
			assend = false;

		if (v.at(i-1) < v.at(i))
			dessend = false;

		if (!assend && !dessend)
			throw std::runtime_error("Numbers are not sorted");
	}
}
