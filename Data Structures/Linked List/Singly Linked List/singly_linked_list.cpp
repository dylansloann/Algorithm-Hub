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
SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr),  _size(0) {}

// copy constructor
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
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
	
	// updates _size and tail
	_size = other._size;
	tail = current;
}

// copy assignment operator
SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& rhs) {
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
	
	// updates _size and tail
	_size = rhs._size;
	tail = current;

	return *this;
}

// destructor
SinglyLinkedList::~SinglyLinkedList() { clear(); }

// checking for empty
bool SinglyLinkedList::empty() { 
	if (_size == 0) { return true; }
	else { return false; }
}

// obtaining _size
int SinglyLinkedList::size() { return _size; }

// clears list of all nodes
void SinglyLinkedList::clear() {
	Node* temp;
	for (int i = 0; i < _size; i++) {
		temp = head;
		head = head->link;
		delete temp;
	}

	// reset ptr values/_size
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

// creates list from single node
void SinglyLinkedList::create_single(Node* node) {
	head = node;
	tail = node;
	node->link = nullptr;
	_size = 1;
}

// deletes list of a single node
void SinglyLinkedList::remove_single() {
	delete head;
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

// inserting at front
void SinglyLinkedList::push_front(int value) {
	Node* node = new Node(value);

	if (empty()) { create_single(node); }

	else {
		node->link = head;
		head = node;
		_size++;
	}
}

// inserting at back
void SinglyLinkedList::push_back(int value) {
	Node* node = new Node(value);

	if (empty()) { create_single(node); }

	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

// inserting at index
void SinglyLinkedList::insert(int value, int index) {
	// error checking
	if (index > _size) { throw std::invalid_argument("Index too large."); }

	// inserting at front/back
	else if (index == 0) { push_front(value); return; }
	else if (index == _size) { push_back(value); return; }

	// creating node
	Node* node = new Node(value);

	if (empty()) { create_single(node); }
	
	else {
		Node* current = head;
		Node* previous = head;
		for (int i = 0; i < _size; i++) {
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
bool SinglyLinkedList::contains(int value) {
	Node* current = head;
	for (int i = 0; i < _size; i++) {
		if (current->data == value) {
			return true;
		}
		current = current->link;
	}

	// if no value was found
	return false;
}

// removing at front
void SinglyLinkedList::remove_front() {
	// pre empty list
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node
	else if (_size == 1) { remove_single(); }

	else {
		Node* temp;
		temp = head;
		head = head->link;
		delete temp;
		_size--;
	}
}

// removing at back
void SinglyLinkedList::remove_back() {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node
	else if (_size == 1) { remove_single(); return; }

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
void SinglyLinkedList::remove(int index) {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	// if list contains single node
	else if (_size == 1 && index == 0) { remove_single(); return; }

	// if value is at front
	else if (index == 0) { remove_front(); return; }

	Node* current = head;
	Node* previous = head;
	for (int i = 0; i < index; i++) {
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

	_size--;
}

void SinglyLinkedList::reverse() {
    tail = head;
	Node* current = head;
    Node* previous = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

// obtains first node
const Node* SinglyLinkedList::front() { return head; }

// obtains last node
const Node* SinglyLinkedList::back() { return tail; }

// displays list with values and links
void SinglyLinkedList::display() {
	Node* current = head;
	for (int i = 0; i < _size; i++) {
		cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	cout << endl;
}
