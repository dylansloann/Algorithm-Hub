#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include <iostream>

class Node {
	public:
		int data;
		Node* link;
		// constructors
		Node();
		Node(int value);
};

class LinkedStack {
	private:
		Node* head;
		int _size;
	public:
		// constructors/destructor
		LinkedStack();
		LinkedStack (const LinkedStack& other);
		LinkedStack& operator=(const LinkedStack& rhs);
		~LinkedStack();

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