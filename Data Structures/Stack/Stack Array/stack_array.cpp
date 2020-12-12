#include "stack_array.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Stack ==================

// default constructor
Stack::Stack() : stackArray(new int[2]), capacity(2), length(0) {} 

// copy constructor
Stack::Stack(const Stack& other) {
	capacity = other.capacity;
	length = other.length;
	stackArray = new int[capacity];

	for (size_t i = 0; i < length; i++) {
		stackArray[i] = other.stackArray[i];
	}
}

// copy assignment operator
Stack& Stack::operator=(const Stack& rhs) {
	if (stackArray == rhs.stackArray) {return *this;}

	clear();

	capacity = rhs.capacity;
	length = rhs.length;
	stackArray = new int[capacity];

	for (size_t i = 0; i < length; i++) {
		stackArray[i] = rhs.stackArray[i];
	}

	return *this;
}

// destructor
Stack::~Stack() { clear(); }

// pushing/adding item onto end of the stack
void Stack::push(int data) {
	if (length == capacity) {
		int* doubledStackArray = new int[2 * capacity];
		for (size_t i = 0; i < capacity; i++) { 
			doubledStackArray[i] = stackArray[i]; 
		}
		delete [] stackArray;
		capacity = 2 * capacity;
		stackArray = doubledStackArray;
	}

	stackArray[length] = data;
	length++;
}

// popping/removing item from end of the stack
int Stack::pop() { 
	if (empty()) { throw std::logic_error("Removing from empty stack"); }
	length--;
	return stackArray[length];
}

// returns peek/last element in the stack
int Stack::peek() { return stackArray[length - 1]; }

// returns length/size of the stack
int Stack::size() { return length; }

// returns if stack is empty
bool Stack::empty() { if (length == 0) { return true; } else { return false; } }

// empties stack
void Stack::clear() { delete [] stackArray; }

// displays stack
void Stack::display() {
	for (size_t i = 0; i < length; i++) {
		cout << stackArray[i] << " ";
	}
	cout << endl;
}