// programming assignment 3

#include "DoublyLinkedList.h"
#include <stdexcept>


// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
	// Initialize the list
	header.next = &trailer;
	trailer.prev = &header;
	DListNode* temp = dll.getFirst();

	// Copy from dll
	// Complete this function
	while (temp->getNext()) {
		this->insertLast(temp->getElem());
		temp = temp->getNext();
	}
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
	// Complete this function

	if (this != &dll) { // Check for self-assignment, like: a = a;
		header.next = &trailer;
		trailer.prev = &header;
		DListNode* temp = dll.getFirst();
		// this->clear();

		// Allocate new memory & Copy data from source
		while (temp->getNext()) {
			this->insertLast(temp->getElem());
			temp = temp->getNext();
		}
	}
	return *this;
}

// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{
	DListNode *newNode = new DListNode(newobj, &header, header.next);
	DListNode* ptr = header.next;
	// Complete this function
	// Insert before head
	this->header.next = newNode;
	newNode->next = ptr;
}

// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
	DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
	trailer.prev->next = newNode;
	trailer.prev = newNode;
}

// remove the first object of the list
int DoublyLinkedList::removeFirst()
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	// Complete this function
	DListNode *node = header.next;
	node->next->prev = &header;
	header.next = node->next;
	int obj = node->obj;
	delete node;
	return obj;
}

// remove the last object of the list
int DoublyLinkedList::removeLast()
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	DListNode *node = trailer.prev;
	node->prev->next = &trailer;
	trailer.prev = node->prev;
	int obj = node->obj;
	delete node;
	return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
	DListNode *prev_node, *node = header.next;
	while (node != &trailer)
	{
		prev_node = node;
		node = node->next;
		delete prev_node;
	}
	header.next = &trailer;
	trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");
	// Complete this function
	return header.next->getElem();
}

// return the last object
int DoublyLinkedList::last() const
{
	if (isEmpty())
		throw EmptyDLinkedListException("Empty Doubly Linked List");

	// return count;
	return trailer.prev->getElem();
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	// Complete this function
	DListNode* temp = dll.getFirst();

	while (temp->getNext()) {
		out << temp->getElem() << " ";
		temp = temp->getNext();
	}
	return out;
}
