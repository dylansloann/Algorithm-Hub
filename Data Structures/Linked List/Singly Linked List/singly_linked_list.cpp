#include "singly_linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

// ================== Node ==================

// default constructor
Node::Node() : data(0), link(nullptr) {}

// constructor with value
Node::Node(int value) : data(value), link(nullptr) {}



// ================== Linked List ==================

// default constructor
List::List() : head(nullptr), tail(nullptr),  _size(0) {}

// copy constructor
List::List(const List& other) {
	// if other list is empty
	if (other.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return; }

	// reasigns new nodes, iterators
	head = new Node(other.head->data);
	Node* current = head;
	Node* tempCurrent = other.head;

	// iterates till other reaches tail
	while (tempCurrent->link != nullptr) {
		Node* node = new Node(tempCurrent->link->data);
		current->link = (node);
		current = current->link;
		tempCurrent = tempCurrent->link;
	}
	
	// updates size and tail
	_size = other._size;
	tail = current;
}

// copy assignment operator
List& List::operator=(const List& rhs) {
	// checks for self equal/empty
	if (head == rhs.head && tail == rhs.tail && _size == rhs._size) { return *this; }
	else if (rhs.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return *this; }

	// clears lhs list
	clear();

	// reasigns new nodes, iterators
	head = new Node(rhs.head->data);
	Node* current = head;
	Node* tempCurrent = rhs.head;

	// iterates till rhs reaches tail
	while (tempCurrent->link != nullptr) {
		Node* node = new Node(tempCurrent->link->data);
		current->link = (node);
		current = current->link;
		tempCurrent = tempCurrent->link;
	}
	
	// updates size and tail
	_size = rhs._size;
	tail = current;

	return *this;
}

// destructor
List::~List() { clear(); }

// checking for empty
bool List::empty() { 
	if (_size == 0) { return true; }
	else { return false; }
}

// obtaining size
int List::size() { return _size; }

// clears list of all nodes
void List::clear() {
	Node* temp;
	for (size_t i = 0; i < _size; i++) {
		temp = head;
		head = head->link;
		delete temp;
	}

	// reset ptr values/size
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

// creates list from single node
void List::create_single(Node* node) {
	head = node;
	tail = node;
	node->link = nullptr;
	_size = 1;
}

// deletes list of a single node
void List::remove_single() {
	delete head;
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

// inserting at front
void List::push_front(int value) {
	// creating node
	Node* node = new Node(value);
	
	// pre empty list
	if (empty()) { create_single(node); }

	// list pre containing elements
	else {
		node->link = head;
		head = node;
		_size++;
	}
}

// inserting at back
void List::push_back(int value) {
	// creating node
	Node* node = new Node(value);

	// pre empty list
	if (empty()) { create_single(node); }

	// list pre containing elements
	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

// inserting at index
void List::insert(int value, size_t index) {
	// error checking
	if (index > _size) { throw std::invalid_argument("Index too large."); }

	// inserting at front/back
	else if (index == 0) { push_front(value); return; }
	else if (index == _size) { push_back(value); return; }

	// creating node
	Node* node = new Node(value);

	// pre empty list
	if (empty()) { create_single(node); }
	
	// inserting in middle
	else {
		Node* current = head;
		Node* previous = head;
		for (size_t i = 0; i < _size; i++) {
			if (i == index) {
				previous->link = node;
				node->link = current;
				_size++;
				return;
			}
			previous = current;
			current = current->link;
		}
	}
}

// determines if list contains value
bool List::contains(int value) const {
	Node* newCurrent = head;
	for (size_t i = 0; i < _size; i++) {
		if (newCurrent->data == value) {
			return true;
		}
		newCurrent = newCurrent->link;
	}

	// if no value was found
	return false;
}

// removing at front
void List::remove_front() {
	// pre empty list
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node
	else if (_size == 1) { remove_single(); }

	// list pre containing more than 1 element
	else {
		Node* temp;
		temp = head;
		head = head->link;
		delete temp;
		_size--;
	}
}

// removing at back
void List::remove_back() {
	// pre empty list
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node
	else if (_size == 1) { remove_single(); return; }

	// list pre containing more than 1 element
	Node* current = head;
	Node* previous = head;
	while (current != nullptr) {
		previous = current;
		current = current->link;
	}
	delete current;
	tail = previous;
	previous->link = nullptr;
	_size--;
}

// removing index in middle
void List::remove(size_t index) {
	// pre empty list
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node with value
	else if (_size == 1 && index == 0) { remove_single(); return; }

	// if value is at front
	else if (index == 0) { remove_front(); return; }

	Node* current = head;
	Node* previous = head;
	for (size_t i = 0; i < index; i++) {
		previous = current;
		current = current->link;
	}

	// if value is at back
	if (current->link == nullptr) { 
		delete current;
		tail = previous;
		previous->link = nullptr;
	}

	// if value is in middle
	else {
		previous->link = current->link;
		delete current;
	}

	// decrement size
	_size--;
}

// obtains value of first node
int List::front() { return head->data; }

// obtains value of last node
int List::back() { return tail->data; }

// displays list with values and links
void List::display() {
	Node* current = head;
	for (size_t i = 0; i < _size; i++) {
		cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	cout << endl;
}
