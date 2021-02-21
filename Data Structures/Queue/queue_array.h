#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>

template <typename T>
class Queue {
	private:
		T* queueArray;
		int capacity;
		int _size;
		int front, back;
	public:
		Queue();
		Queue(const Queue& other);
		Queue& operator=(const Queue& rhs);
		~Queue();

		void enqueue(T data);
		T dequeue();

		int size();
		bool empty();

		void display();
};

/*
   Default Constructor
*/
template <typename T>
Queue<T>::Queue() : queueArray(nullptr), capacity(0), _size(0), front(-1), back(-1) {}

/*
   Copy Constructor

   @param  other	secondary queue to copy
*/
template <typename T>
Queue<T>::Queue(const Queue<T>& other) : queueArray(new int[capacity]), capacity(other.capacity), _size(other._size), front(other.front), back(other.back) {
	for (int i = front; i <= back; i++) {
		queueArray[i] = other.queueArray[i];
	}
}

/*
   Copy Assignment Operator

   @param  rhs	secondary Queue to copy
   @return Queue<T>& 	refrence to queue once fully copied
*/
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
	if (queueArray == rhs.queueArray) {return *this;}

	delete [] queueArray;

	capacity = rhs.capacity;
	_size = rhs._size;
	front = rhs.front;
	back = rhs.back;
	queueArray = new int[capacity];

	for (int i = front; i <= back; i++) {
		queueArray[i] = rhs.queueArray[i];
	}

	return *this;
}

/*
   Destructor
*/
template <typename T>
Queue<T>::~Queue() { delete [] queueArray; }

/*
   Inserts (enqueues) element at back of queue (back = newer)

   @param  data		data of element to be enqueued
   @return void
*/
template <typename T>
void Queue<T>::enqueue(T data) {
	if (_size == capacity) {
		if (capacity == 0) capacity = 1;
		capacity *= 2;
		T* doubledQueueArray = new T[capacity];
		for (int i = 0; i < _size; i++) { 
			doubledQueueArray[i] = queueArray[i]; 
		}
		delete [] queueArray;
		queueArray = doubledQueueArray;
	}

	_size++;
	back++;
	queueArray[back] = data;

	// if queue is empty shift front index
	if (front == -1) {
		front = 0;
	}
}

/*
   Increamentes front value to "remove" first element (oldest) from Queue

   @param  none
   @return T	returns element that was dequeued
*/
template <typename T>
T Queue<T>::dequeue() {
	if (empty()) { throw std::logic_error("Dequeueing from empty queue"); }

	T returnValue = queueArray[front];
	front++;

	if (_size == 1) {
		front = -1;
		back = -1;
	}

	_size--;
	return returnValue;
}

/*
   Obtains size of Queue

   @param  none
   @return int	returns _size attribute
*/
template <typename T>
int Queue<T>::size() { return _size; }

/*
   Checks if Queue is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool Queue<T>::empty() { if (_size == 0) { return true; } else { return false; } }

/*
   Displays Queue seperated by spaces

   @param  none
   @return void
*/
template <typename T>
void Queue<T>::display() {
	if (_size == 0) { return; }
	for (int i = front; i <= back; i++) {
		std::cout << queueArray[i] << " ";
	}
	std::cout << std::endl;
}

#endif