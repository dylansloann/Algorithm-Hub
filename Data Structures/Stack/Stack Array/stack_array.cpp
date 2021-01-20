#include "stack_array.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Stack ==================

Stack::Stack() : stackArray(new int[2]), capacity(2), _size(0) {} 

Stack::Stack(const Stack& other) {
	capacity = other.capacity;
	_size = other._size;
	stackArray = new int[capacity];

	for (int i = 0; i < _size; i++) {
		stackArray[i] = other.stackArray[i];
	}
}

Stack& Stack::operator=(const Stack& rhs) {
	if (stackArray == rhs.stackArray) {return *this;}

	delete [] stackArray;

	capacity = rhs.capacity;
	_size = rhs._size;
	stackArray = new int[capacity];

	for (int i = 0; i < _size; i++) {
		stackArray[i] = rhs.stackArray[i];
	}

	return *this;
}

Stack::~Stack() { delete [] stackArray; }

void Stack::push(int data) {
	// doubles capacity if stack is full
	if (_size == capacity) {
		int* doubledStackArray = new int[2 * capacity];
		for (int i = 0; i < capacity; i++) { 
			doubledStackArray[i] = stackArray[i]; 
		}
		delete [] stackArray;
		capacity = 2 * capacity;
		stackArray = doubledStackArray;
	}

	stackArray[_size] = data;
	_size++;
}

int Stack::pop() { 
	if (empty()) { throw std::logic_error("Popping from empty stack"); }
	_size--;
	return stackArray[_size];
}

int Stack::peek() { return stackArray[_size - 1]; }

int Stack::size() { return _size; }

bool Stack::empty() { if (_size == 0) { return true; } else { return false; } }

void Stack::display() {
	for (int i = 0; i < _size; i++) {
		cout << stackArray[i] << " ";
	}
	cout << endl;
}