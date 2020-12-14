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

class Queue {
	private:
		int* queueArray;
		int length;
		int front, back;
	public:
		// constructors/destructor
		Queue();
		Queue(const Queue& other);
		Queue& operator=(const Queue& rhs);
		~Queue();

		// operations
		void enqueue(int data);
		int dequeue();

		// size operations
		int size();
		bool empty();

		// display queue
		void display();
};