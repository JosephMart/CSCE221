#ifndef HASH
#define HASH

#include <string>
#include <iostream>

class hash
{
    private:
        static const int tableSize = 20;

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
        void PrintTable();

        int size();
        // std::vector<LinkedList<HashNode>> get_vec();
        int searchGrade(unsigned int key);

        // LinkedList<HashNode>& operator [] (int index);
};

// std::ostream& operator << (std::ostream& out, HashTable& htable);

#endif
