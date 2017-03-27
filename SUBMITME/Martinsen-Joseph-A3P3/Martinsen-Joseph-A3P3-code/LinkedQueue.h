//============================================================================
// Name        : LinkedQueue.h
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : File for LinkedQueue
//============================================================================

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template<typename T> class LinkedQueue;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template<typename T>
class LinkedQueue {
private:
   /* declare member variables here */
    DoublyLinkedList<T> dll; // Doubly Linked List
public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

   /* declare rest of functions */
    LinkedQueue<T>() : dll() { }                     // Constructor
    LinkedQueue<T>(const LinkedQueue<T>& lq);        // Copy Constructor
    ~LinkedQueue<T>() { dll.~DoublyLinkedList(); }   // Destructor
    T first() const throw(QueueEmptyException);      // Return First elem
    bool isEmpty() const throw(QueueEmptyException); // True if empyt que
    void enqueue(T elem) { dll. insertLast(elem); }  // Add elem to que
    T dequeue() throw(QueueEmptyException);          // Remove top of que
    const DoublyLinkedList<T> getDLL() const;        // Access DoublyLinkedList
};

/* describe rest of the functions here */
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& lq)
{
    dll = lq.getDLL();
}

template <typename T>
T LinkedQueue<T>::first() const throw(QueueEmptyException)
{
    if (dll.isEmpty())
        throw QueueEmptyException();
    return dll.first();
}

template <typename T>
T LinkedQueue<T>::dequeue() throw(QueueEmptyException)
{
    if (dll.isEmpty())
        throw QueueEmptyException();
    return dll.removeFirst();
}

template <typename T>
const DoublyLinkedList<T> LinkedQueue<T>::getDLL() const {
    return dll;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue)
{
    DoublyLinkedList<T> dll = queue.getDLL();
    DListNode<T>* node = dll.getFirst();
    while(node != dll.getAfterLast()->getPrev())
    {
        out << node->getElem().kind;
        node = node->getNext();
    }
    return out;
}

#endif
