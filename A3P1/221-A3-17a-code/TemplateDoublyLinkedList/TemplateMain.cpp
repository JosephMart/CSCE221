// programming assignment 3

#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  std::cout << "DoublyLinkedList Template Testing" << '\n';
  cout << "Create a new int and string list" << endl;
  DoublyLinkedList<string> dll;
  DoublyLinkedList<int> dlli;
  cout << "list(string): " << dll << endl;
  cout << "   " << "list(int): " << dlli << endl << endl;
  //
  // // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  for (int i=10;i<=100;i+=10) {
		dlli.insertLast(i);
	}
  cout << "list(string): " << dll << endl;
  cout << "   " << "list(int): " << dlli << endl << endl;

  // Get first and last item
	std::cout << "Print first and last item" << '\n';
	std::cout << "first(string): " << dll.first() << '\n';
	std::cout << " last(string): " << dll.last() << "\n";
  std::cout << "   first(int): " << dlli.first() << '\n';
	std::cout << "    last(int): " << dlli.last() << "\n\n";

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  for (int i=10;i<=100;i+=10) {
		dlli.insertFirst(i);
	}
  cout << "list(string): " << dll << endl;
  cout << "   list(int): " << dll << endl << endl;

  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList<string> dll2(dll);
  DoublyLinkedList<int> dll2i(dlli);
  cout << "list2(string): " << dll2 << endl;
  cout << "   list2(int): " << dll2i << endl << endl;

  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList<string> dll3;
  DoublyLinkedList<int> dll3i;
  dll3=dll;
  dll3i=dlli;
  cout << "list3(string): " << dll3 << endl;
  cout << "   list3(int): " << dll3i << endl << endl;

  // Delete the last 10 nodes
  cout << "Delete the last 5 nodes" << endl;
  for (int i=0; i<5; i++) {
    dll.removeLast();
    dlli.removeLast();
  }
  cout << "list(string): " << dll << endl;
  cout << "   list(int): " << dlli << endl << endl;

  // Delete the first 10 nodes
  cout << "Delete the first 5 nodes" << endl;
  for (int i=0; i<5; ++i) {
    dll.removeFirst();
    dlli.removeFirst();
  }
  cout << "list(string): " << dll << endl;
  cout << "   list(int): " << dlli << endl << endl;

  // Check the other two lists
  cout << "Make sure the other four lists are not affected." << endl;
  cout << "list2(string): " << dll2 << endl;
  cout << "list3(string): " << dll3 << endl;
  cout << "   list2(int): " << dll2i << endl;
  cout << "   list3(int): " << dll3i << endl;

  return 0;
}
