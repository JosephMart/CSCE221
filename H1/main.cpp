#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// Sources
// https://www.youtube.com/watch?v=keEcyZfrmxY

void readFile(std::vector<int>* v, std::string fileName);
void results(int value, int mid, int comp, bool found, std::vector<int> v);

int main(int argc, char const *argv[]) {
	try{

		std::vector<int> v;
		bool assend = true;
		bool dessend = true;
		bool found = false;
		int low = 0;
		int high = 0;
		int mid = 0;
		int value = 10;
		int comp = 0;

		readFile(&v, "in.txt");
		high = v.size() - 1;

		// Confrim that vector is sorted
		for (int i = 1; i < v.size(); i++)
		{
			if (v.at(i-1) > v.at(i))
				assend = false;

			if (v.at(i-1) < v.at(i))
				dessend = false;

			if (!assend && !dessend)
				throw std::runtime_error("Numbers are not sorted");
		}

		// Ask user what value to search for
		std::cout << "Enter number to search: ";
		std::cin >> value;

		// Binary Search
		while (low <= high && !found) {
			comp++;
			mid = (low + high) / 2;
			if (v[mid] > value){
				high = mid - 1;
				comp++;
			} else if (v[mid] < value) {
				low = mid + 1;
				comp += 2;
			}
			else {
				found = true;
				comp += 2;
			}
		}

		results(value, mid, comp, found, v);

		return 0;
	}
	catch(std::runtime_error& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
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
	std::cout << "in { ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i);
		if (i != v.size() - 1) {
			std::cout << ",";
		}
		std::cout << " ";
	}
	std::cout << "}" << '\n';

	if (found) {
		std::cout << "Found at index: " << mid << '\n';
		std::cout << "Number of comparisons: " << comp << '\n';
	} else {
		std::cout << "Not found" << '\n';
	}
}
