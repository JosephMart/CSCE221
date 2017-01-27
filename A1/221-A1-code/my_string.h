#ifndef MY_STRING
#define MY_STRING

#include <iostream>

class my_string
{
private:
    char *ptr;
    int sz;
    int cap;

public:
    my_string();
    my_string(int n);
    my_string(char const c[]);
    my_string(const my_string& q);
    ~my_string();

    int size() const { return sz; }
    int capacity() const { return cap; }
    bool empty() const { return !sz; }
    char& at(int i) const;
    // insert(int i, std::string s);

    char& operator[](int i) const;
    my_string& operator+=(const my_string& q);
    my_string& operator+=(char const c);
    my_string& operator=(const my_string & q);
    friend std::istream& operator>>(std::istream& is, my_string& q);
};

std::ostream& operator<<(std::ostream& os, const my_string& q);


#endif
