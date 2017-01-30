#include "my_string.h"
#include <stdexcept>

my_string::my_string() : sz(0), cap(0) {
    ptr = new char[0];
    // ptr[0] = '';
}

my_string::my_string(int n)
{
    // Set initial values
    this->ptr = new char[n];
    this->sz = 0;
    this->cap = n;
}
my_string::my_string(char const c[])
{
    this->sz = 0;

    while (c[this->sz] != '\0') {
        ++this->sz;
    }

    this->ptr = new char[sz];

    this->cap = this->sz;

    for (int i = 0; i < this->sz; i++) {
        this->ptr[i] = c[i];
    }
}

my_string::my_string(const my_string & q)
{
    this->ptr = new char[q.capacity()];
    this->sz = q.size();
    this->cap = q.capacity();

    for (int i = 0; i < q.size(); i++) {
        this->ptr[i] = q[i];
    }
}

my_string::~my_string()
{
    if (ptr != NULL) {
        delete[] ptr;
        ptr = NULL;
    }
}

char& my_string::at(int i) const
{
    if (i <= this->capacity()+1 && i >= 0)
        return this->ptr[i];

    throw std::out_of_range("Out of range");
}

char& my_string::operator[](int i) const
{
    char *temp = this->ptr;
    return *(temp += i);
}


void my_string::resize(int size)
{
    if (size > this->cap) {
        my_string temp = *this;
        delete[] this->ptr;
        // Assign new size
        this->cap = 2*(this->cap + size+1);
        this->ptr = new char[this->cap];

        for (int i = 0; i < temp.size(); i++) {
            this->ptr[i] = temp[i];
        }
    }
}

my_string& my_string::operator=(const my_string& q)
{
    if (q.capacity() > this->cap ) {
        delete[] this->ptr;
        this->ptr = new char[q.capacity()];
    }

    this->cap = q.capacity();
    this->sz = q.size();

    for (int i = 0; i < q.capacity(); i++) {
        this->ptr[i] = q[i];
    }
    return *this;
}

my_string& my_string::operator+=(const my_string& q)
{
    this->resize(this->sz + q.capacity());

    for (int i = 0; i <= q.size(); i++) {
        this->sz++;
        this->ptr[this->sz] = q[i];
    }
    return *this;
}

my_string& my_string::operator+=(char const c)
{
    this->resize(1);
    this->ptr[this->sz] = c;
    this->sz++;
    return *this;
}

my_string& my_string::insert(int pos, const my_string& s)
{
    // temp my_string to hold char after pos
    my_string temp;

    for (int i = pos; i < this->sz; i++) {
        temp += this->ptr[i];
    }


    this->resize(this->sz += s.size());

    // add new my_string s
    for (int i = 0; i < s.size(); i++) {
        this->ptr[pos + i] = s[i];
    }

    for (int i = 0; i < temp.size(); i++) {
        this->ptr[pos + s.size() + i] = temp[i];
    }



    return *this;
}

std::istream& operator>>(std::istream& is, my_string& q)
{
    int c_size = 1;
    if ((c_size + q.sz) > q.cap) {
        my_string temp = q;
        delete q.ptr;
        // Assign new size
        q.cap = q.sz + c_size;
        q.ptr = new char[q.cap];

        for (int i = 0; i < temp.size(); i++) {
            q.ptr[i] = temp[i];
        }
    }
    is >> q.ptr[q.sz];

    return is;
}

std::ostream& operator<<(std::ostream& os, const my_string& q)
{
    for (int i = 0; i <= q.size(); i++) {
        os << q.at(i);
    }
    return os;
}
