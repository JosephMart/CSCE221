#include "hash.h"

hash::hash()
{
    for (int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i]->uin = 0;
        HashTable[i]->grade = 0;
        HashTable[i]->name = "";
        HashTable[i]->next = nullptr;
    }
}

int hash::Hash(unsigned int uin)
{
    return uin % tableSize;
}

void hash::insert(unsigned int uin, int grade)
{
    int index = Hash(uin);

    if (HashTable[index]->uin == 0)
    {
        HashTable[index]->uin = uin;
        HashTable[index]->grade = grade;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->uin = uin;
        n->grade = grade;
        n->next = nullptr;

        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::ItemsAtIndex(int index)
{
    int count = 0;

    if (HashTable[index]->uin == 0)
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while (Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;

    for (int i = 0; i < tableSize; i++)
    {
        number = ItemsAtIndex(i);
        std::cout << "------------------------" << '\n';
        std::cout << "index:" << i << '\n';
        std::cout << "UIN:" << HashTable[i]->uin << '\n';
        std::cout << "Grade:" << HashTable[i]->grade << '\n';
        std::cout << "# of Items in Bucket:" << number << '\n';
        std::cout << "------------------------" << '\n';
    }
}

int hash::searchGrade(unsigned int uin)
{
    int index = Hash(uin);
    bool uinFound = false;

    int grade = 0;
    item* Ptr = HashTable[index];
    while (Ptr != NULL)
    {
        if (Ptr->uin == uin)
        {
            // std::cout << "UIN: " << uin << '\n';
            grade = Ptr->grade;
            return grade;
            // std::cout << "Grade: " << grade << '\n';
            uinFound = true;
        }
        Ptr = Ptr->next;
    }

    return grade;
    // if (uinFound)
    // {
    //     std::cout << "UIN: " << uin << '\n';
    //     std::cout << "Grade: " << grade << '\n';
    // }
}
