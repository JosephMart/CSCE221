// LinkedQueue.h

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
    DoublyLinkedList<T> dll;
public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

   /* declare rest of functions */
    LinkedQueue<T>() : dll() { }
    ~LinkedQueue<T>() { dll.~DoublyLinkedList(); }
    T first() const throw(QueueEmptyException);
    bool isEmpty() const throw(QueueEmptyException);
    void enqueue(T elem) { dll. insertLast(elem); }
    T dequeue() throw(QueueEmptyException);
    const DoublyLinkedList<T> getDLL() const;
};

/* describe rest of the functions here */
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
  /* fidll in the function */
   return out << queue.getDLL();
}

#endif
