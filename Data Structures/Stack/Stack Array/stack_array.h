#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>

class Stack {
	private:
		int* stackArray;
		size_t capacity;
		size_t length;
	public:
		// constructors/destructor
		Stack();
		Stack(const Stack& other);
		Stack& operator=(const Stack& rhs);
		~Stack();

		// operations
		void push(int data);
		int pop();
		int peek();

		// size operations
		int size();
		bool empty();

		// clears stack
		void clear();

		// display stack
		void display();
};

#endif