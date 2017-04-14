#ifndef HASH
#define HASH

#include <string>
#include <iostream>

class hash
{
    private:
        static const int tableSize = 17;

        struct item {
            unsigned int uin;
            int grade;
            std::string name;
            item* next;
        };

        item* HashTable[tableSize];

    public:
        hash();

        int Hash(unsigned int uin);
        void insert(unsigned int uin, int grade);
        int ItemsAtIndex(int index);
        void PrintTableInfo();
        int searchGrade(unsigned int key);
};

#endif
