#include "stack_array.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Stack ==================

// default constructor
Stack::Stack() : stackArray(new int[2]), capacity(2), _size(0) {} 

// copy constructor
Stack::Stack(const Stack& other) {
	capacity = other.capacity;
	_size = other._size;
	stackArray = new int[capacity];

	for (int i = 0; i < _size; i++) {
		stackArray[i] = other.stackArray[i];
	}
}

// copy assignment operator
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

// destructor
Stack::~Stack() { delete [] stackArray; }

// pushing/adding item onto end of the stack
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

// popping/removing item from end of the stack
int Stack::pop() { 
	if (empty()) { throw std::logic_error("Popping from empty stack"); }
	_size--;
	return stackArray[_size];
}

// returns peek/last element in the stack
int Stack::peek() { return stackArray[_size - 1]; }

// returns length/size of the stack
int Stack::size() { return _size; }

// returns if stack is empty
bool Stack::empty() { if (_size == 0) { return true; } else { return false; } }

// displays stack
void Stack::display() {
	for (int i = 0; i < _size; i++) {
		cout << stackArray[i] << " ";
	}
	cout << endl;
}