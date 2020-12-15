#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>

class Queue {
	private:
		int* queueArray;
		int capacity;
		int _size;
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

#endif