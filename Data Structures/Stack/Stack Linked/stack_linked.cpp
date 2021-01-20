#include "stack_linked.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Node ==================

Node::Node() : data(0), link(nullptr) {}

Node::Node(int value) : data(value), link(nullptr) {}



// ================== Linked Stack ==================

LinkedStack::LinkedStack() : head(nullptr), _size(0) {}

LinkedStack::LinkedStack(const LinkedStack& other) {
	if (other.head == nullptr) { head = nullptr; _size = 0; return; }

	head = new Node(other.head->data);
	Node* current = head;
	Node* tempCurrent = other.head;

	while (tempCurrent->link != nullptr) {
		Node* node = new Node(tempCurrent->link->data);
		current->link = (node);
		current = current->link;
		tempCurrent = tempCurrent->link;
	}
	
	_size = other._size;
}

LinkedStack& LinkedStack::operator=(const LinkedStack& rhs) {
	if (head == rhs.head && _size == rhs._size) { return *this; }
	else if (rhs.head == nullptr) { head = nullptr; _size = 0; return *this; }

	clear();

	head = new Node(rhs.head->data);
	Node* current = head;
	Node* tempCurrent = rhs.head;

	while (tempCurrent->link != nullptr) {
		Node* node = new Node(tempCurrent->link->data);
		current->link = (node);
		current = current->link;
		tempCurrent = tempCurrent->link;
	}
	
	_size = rhs._size;

	return *this;
}

LinkedStack::~LinkedStack() { clear(); }

void LinkedStack::push(int data) {
	Node* node = new Node(data);
	
	if (empty()) { 
		head = node;
		node->link = nullptr;
		_size = 1;
		return;
	}

	else {
		node->link = head;
		head = node;
		_size++;
	}
}

int LinkedStack::pop() { 
	int returnVal = head->data;

	if (empty()) { throw std::logic_error("Popping from empty stack"); }

	else if (_size == 1) {
		delete head;
		head = nullptr;
		_size = 0;
	}

	else {
		Node* temp;
		temp = head;
		head = head->link;
		delete temp;
		_size--;
	}

	return returnVal;
}

int LinkedStack::peek() { return head->data; }

int LinkedStack::size() { return _size; }

bool LinkedStack::empty() { if (_size == 0) { return true; } else { return false; } }

// only for use in destructor/copy assignment operator
void LinkedQueue::clear() {
	Node* temp;
	for (int i = 0; i < _size; i++) {
		temp = head;
		head = head->link;
		delete temp;
	}

	head = nullptr;
	_size = 0;
}

void LinkedStack::display() {
	Node* current = head;
	for (int i = 0; i < _size; i++) {
		cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	cout << endl;
}