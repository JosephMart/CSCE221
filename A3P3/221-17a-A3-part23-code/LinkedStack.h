// LinkedStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);

template<typename T>
class LinkedStack
{
private:
    /* declare member variables here */
    DoublyLinkedList<T> dll;

public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };

    /* declare rest of functions */
    LinkedStack<T>() : dll() { }
    ~LinkedStack<T>() { dll.~DoublyLinkedList(); }
    bool isEmpty() const { return dll.isEmpty(); }
    void push(const T elem) { dll.insertFirst(elem); }
    T pop() throw(StackEmptyException);
    T top() const throw (StackEmptyException);
    const DoublyLinkedList<T> getDLL() const;
};

/* describe rest of the functions here */
template <typename T>
T LinkedStack<T>::pop() throw(StackEmptyException) {
    if (dll.isEmpty())
        throw StackEmptyException();
    return dll.removeFirst();
}

template <typename T>
T LinkedStack<T>::top() const throw(StackEmptyException) {
if (dll.isEmpty())
    throw StackEmptyException();
return dll.first();
}

template <typename T>
const DoublyLinkedList<T> LinkedStack<T>::getDLL() const {
    return dll;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
  /* fill in the function */
   return out << stack.getDLL();
}

#endif
