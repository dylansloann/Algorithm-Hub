#include "queue_array.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Queue ==================

// default constructor
Queue::Queue() : queueArray(new int[2]), capacity(2), size(0), front(-1), back(-1) {}

// copy constructor
Queue::Queue(const Queue& other) {
	capacity = other.capacity;
	size = other.size;
	front = other.front;
	back = other.back;
	queueArray = new int[capacity];

	for (int i = front; i <= back; i++) {
		queueArray[i] = other.queueArray[i];
	}
}

// copy assignment operator
Queue& Queue::operator=(const Queue& rhs) {
	if (queueArray == rhs.queueArray) {return *this;}

	delete [] queueArray;

	capacity = rhs.capacity;
	size = rhs.size;
	front = rhs.front;
	back = rhs.back;
	queueArray = new int[capacity];

	for (int i = front; i <= back; i++) {
		queueArray[i] = rhs.queueArray[i];
	}

	return *this;
}

// destructor
Queue::~Queue() { delete [] queueArray; }

// enqueing element to the back of the queue
void Queue::enqueue(int data) {
	if (size == capacity) {
		int* doubledQueueArray = new int[2 * capacity];
		for (int i = 0; i < capacity; i++) { 
			doubledQueueArray[i] = queueArray[i]; 
		}
		delete [] queueArray;
		capacity = 2 * capacity;
		queueArray = doubledQueueArray;
	}

	size++;
	back++;
	queueArray[back] = data;

	// if queue is empty shift front index
	if (front == -1) {
		front = 0;
	}
}

// dequeing element from front of the queue
int Queue::dequeue() {
	if (empty()) { throw std::logic_error("Dequeueing from empty queue"); }

	int returnValue = queueArray[front];
	
	// increament front index
	front++;

	// if queue only contains one element
	if (size == 1) {
		front = -1;
		back = -1;
	}

	size--;
	return returnValue;
}

// returns length/size of the queue
int Queue::size() { return size; }

// returns if queue is empty
bool Queue::empty() { if (size == 0) { return true; } else { return false; } }

// displays queue
void Queue::display() {
	if (size == 0) { return; }
	for (int i = front; i <= back; i++) {
		cout << queueArray[i] << " ";
	}
	cout << endl;
}