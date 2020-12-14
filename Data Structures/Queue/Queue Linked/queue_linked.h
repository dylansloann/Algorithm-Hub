#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

#include <iostream>

class Node {
	public:
		int data;
		Node* link;
		// constructors
		Node();
		Node(int value);
};

class LinkedQueue {
	private:
		int _size;
		Node* head;
		Node* tail;
	public:
		// constructors/destructor
		LinkedQueue();
		LinkedQueue(const LinkedQueue& other);
		LinkedQueue& operator=(const LinkedQueue& rhs);
		~LinkedQueue();

		// operations
		void enqueue(int data);
		int dequeue();

		// size operations
		int size();
		bool empty();

		// only for use in destructor/copy assignment operator
		void clear();

		// display queue
		void display();
};

#endif