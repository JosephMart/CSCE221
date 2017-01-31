#include "my_string.h"

my_string::my_string() : sz(0), cap(0) {
    ptr = NULL;
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

    // Get size of c[]
    while (c[this->sz] != '\0')
        ++this->sz;

    // Initialize ptr of size length of/ c
    this->ptr = new char[sz];
    this->cap = this->sz;

    // Add c[] to my_string
    for (int i = 0; i < this->sz; i++)
        this->ptr[i] = c[i];
}

my_string::my_string(const my_string & q)
{
    // Initialize ptr, size, and cap to match q
    this->ptr = new char[q.capacity()];
    this->sz = q.size();
    this->cap = q.capacity();

    // Add q my_string to this my_string
    for (int i = 0; i < q.size(); i++) {
        this->ptr[i] = q[i];
    }
}

my_string::~my_string()
{
    if (ptr != nullptr) {
        delete[] ptr;
        ptr = nullptr;
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
    return (this->ptr[i]);
}

void my_string::resize(int size)
{
    if (size >= this->cap) {
        // Create temp my_string to hold current my_string
        my_string temp = *this;
        delete[] this->ptr;

        // Assign new size
        this->cap = 2*(size+1);
        this->ptr = new char[this->cap];

        // Add temp back into current my_string
        for (int i = 0; i < temp.size(); i++)
            this->ptr[i] = temp[i];
    }
}

my_string& my_string::operator=(const my_string& q)
{
    // If copying the same, return same
    if (this == &q) return *this;

    // Resize if q cap greater
    if (q.capacity() > this->cap )
    {
        delete[] this->ptr;
        this->ptr = new char[q.capacity()];
    }

    this->cap = q.capacity();
    this->sz = q.size();

    // Add q my_string to this my_string
    for (int i = 0; i < q.size(); i++)
        this->ptr[i] = q[i];

    return *this;
}

my_string& my_string::operator+=(const my_string& q)
{
    this->resize(this->sz + q.size());

    // Add q my_string to current my_string
    for (int i = 0; i < q.size(); i++) {
        this->ptr[this->sz] = q[i];
        this->sz++;
    }
    return *this;
}

my_string& my_string::operator+=(char const c)
{
    this->resize(this->sz + 1);
    this->ptr[this->sz] = c;
    this->sz++;
    return *this;
}

my_string& my_string::insert(int pos, const my_string& s)
{
    if(pos >= 0 && pos <= sz)
    {
        // temp my_string to hold char after pos
        my_string temp;

        // Add values after pos to temp
        for (int i = pos; i < this->sz; i++) {
            temp += this->ptr[i];
        }

        this->resize(this->sz += s.size());

        // add new my_string s
        for (int i = 0; i < s.size(); i++) {
            this->ptr[pos + i] = s[i];
        }

        // Add end of string back from temp
        for (int i = 0; i < temp.size(); i++) {
            this->ptr[pos + s.size() + i] = temp[i];
        }

        return *this;
    }
    throw std::out_of_range("Out of range");
}

std::istream& operator>>(std::istream& is, my_string& q)
{
    char c;

    while (c = is.get()) {
        if (c == '\n' || c == ' ') break;

        q.resize(q.sz + 1);
        q[q.sz] = c;
        q.sz++;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const my_string& q)
{
    for (int i = 0; i < q.size(); i++) {
        os << q.at(i);
    }
    return os;
}
