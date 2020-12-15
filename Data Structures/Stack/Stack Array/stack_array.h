#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

class Stack {
	private:
		int* stackArray;
		int capacity;
		int _size;
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

		// display stack
		void display();
};

#endif