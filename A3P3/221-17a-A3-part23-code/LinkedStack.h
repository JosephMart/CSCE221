//============================================================================
// Name        : LinkedStack.h
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : File for LinkedStack
//============================================================================

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
    DoublyLinkedList<T> dll; // Doubly Linked List

public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };

    /* declare rest of functions */
    LinkedStack<T>() : dll() { }                       // Constructor
    ~LinkedStack<T>() { dll.~DoublyLinkedList(); }     // Destructor
    bool isEmpty() const { return dll.isEmpty(); }     // True if empty
    void push(const T elem) { dll.insertFirst(elem); } // Push elem to stack
    T pop() throw(StackEmptyException);                // Pop top of stack
    T top() const throw (StackEmptyException);         // Get top of stack
    const DoublyLinkedList<T> getDLL() const;          // Get DoublyLinkedList
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
    return out << stack.getDLL();
}

#endif
