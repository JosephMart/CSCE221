#include "hash.h"

#include <string>
#include <iostream>

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

void hash::PrintTableInfo()
{
    int count = 0;
    int items;
    int max = ItemsAtIndex(0);
    int min = ItemsAtIndex(0);

    for (int i = 0; i < tableSize; i++)
    {
        items = ItemsAtIndex(i);
        count += items;

        if (max < items)
            max = items;

        if(min > items)
            min = items;
    }

    std::cout << "Hash Table Info" << '\n' << '\n'
              << "Size: " << tableSize << '\n'
              << "Min Items in Bucket: " << min << '\n'
              << "Max Items in Bucket: " << max << '\n'
              << "Avg Items in Bucket: " << count/tableSize << '\n';
}

int hash::searchGrade(unsigned int uin)
{
    int index = Hash(uin);
    bool uinFound = false;
    item* Ptr = HashTable[index];

    while (Ptr != NULL)
    {
        if (Ptr->uin == uin)
            return Ptr->grade;

        Ptr = Ptr->next;
    }
    return 0;
}
