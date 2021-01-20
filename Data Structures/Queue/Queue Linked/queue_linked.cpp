#include "queue_linked.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Node ==================

Node::Node() : data(0), link(nullptr) {}

Node::Node(int value) : data(value), link(nullptr) {}



// ================== Linked Queue ==================

LinkedQueue::LinkedQueue() : _size(0), head(nullptr), tail(nullptr) {}

LinkedQueue::LinkedQueue(const LinkedQueue& other) {
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

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& rhs) {
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

LinkedQueue::~LinkedQueue() { clear(); }

void LinkedQueue::enqueue(int data) {
	Node* node = new Node(data);
	
	if (empty()) { 
		head = node;
		tail = node;
		node->link = nullptr;
		_size = 1;
		return;
	}

	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

int LinkedQueue::dequeue() {
	int returnVal = head->data;

	if (empty()) { throw std::logic_error("Dequeueing from empty queue"); }

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

int LinkedQueue::size() { return _size; }

bool LinkedQueue::empty() { if (_size == 0) { return true; } else { return false; } }

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

void LinkedQueue::display() {
	Node* current = head;
	for (int i = 0; i < _size; i++) {
		cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	cout << endl;
}