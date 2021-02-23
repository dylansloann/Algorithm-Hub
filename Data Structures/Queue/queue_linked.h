#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

template <typename T>
class Node {
	public:
		T data;
		Node* link;
		Node() : data(0), link(nullptr) {}
		Node(T data) : data(data), link(nullptr) {}
};

template <typename T>
class LinkedQueue {
	private:
		int _size;
		Node<T>* head;
		Node<T>* tail;
	public:
		LinkedQueue();
		LinkedQueue(const LinkedQueue& other);
		LinkedQueue& operator=(const LinkedQueue& rhs);
		~LinkedQueue();

		void enqueue(T data);
		T dequeue();

		int size();
		bool empty();

		void clear();
		void display();
};

/*
   Default Constructor
*/
template <typename T>
LinkedQueue<T>::LinkedQueue() : _size(0), head(nullptr), tail(nullptr) {}

/*
   Copy Constructor

   @param  other	secondary queue to copy
*/
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other) : _size(other._size), head(new Node<T>(other.head->data)), tail(nullptr) {
	if (other.head == nullptr) { head = nullptr; _size = 0; return; }

	Node<T>* current = head;
	Node<T>* tmp = other.head;

	while (tmp->link != nullptr) {
		Node<T>* node = new Node<T>(tmp->link->data);
		current->link = (node);
		current = current->link;
		tmp = tmp->link;
	}
}

/*
   Copy Assignment Operator

   @param  rhs	secondary Queue to copy
   @return LinkedQueue<T>& 	refrence to queue once fully copied
*/
template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs) {
	if (head == rhs.head) { return *this; }
	else if (rhs.head == nullptr) { head = nullptr; _size = 0; return *this; }

	clear();

	head = new Node<T>(rhs.head->data);
	Node<T>* current = head;
	Node<T>* tmp = rhs.head;

	while (tmp->link != nullptr) {
		Node<T>* node = new Node<T>(tmp->link->data);
		current->link = (node);
		current = current->link;
		tmp = tmp->link;
	}
	
	_size = rhs._size;

	return *this;
}

/*
   Destructor
*/
template <typename T>
LinkedQueue<T>::~LinkedQueue() { clear(); }

/*
   Inserts (enqueues) element at back of queue (back = newer)

   @param  data		data of element to be enqueued
   @return void
*/
template <typename T>
void LinkedQueue<T>::enqueue(T data) {
	Node<T>* node = new Node<T>(data);
	
	if (empty()) { 
		head = node;
		tail = node;
		node->link = nullptr;
		_size = 1;
	}

	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

/*
   deletes head node and moves to next node

   @param  none
   @return T	returns element that was dequeued
*/
template <typename T>
T LinkedQueue<T>::dequeue() {
	T returnVal = head->data;

	if (empty()) { throw std::logic_error("Dequeueing from empty queue"); }

	else if (_size == 1) {
		delete head;
		head = nullptr;
		_size = 0;
	}

	else {
		Node<T>* temp;
		temp = head;
		head = head->link;
		delete temp;
		_size--;
	}

	return returnVal;
}

/*
   Obtains size of Queue

   @param  none
   @return int	returns _size attribute
*/
template <typename T>
int LinkedQueue<T>::size() { return _size; }

/*
   Checks if Queue is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool LinkedQueue<T>::empty() { 
	if (_size == 0) return true; 
	return false;
}

/*
   Clears queue, same as clearing a linked list (node by node)

   @param  none
   @return void
*/
template <typename T>
void LinkedQueue<T>::clear() {
	Node<T>* temp;
	for (int i = 0; i < _size; i++) {
		temp = head;
		head = head->link;
		delete temp;
	}

	head = nullptr;
	_size = 0;
}

/*
   Displays Queue seperated by arrows

   @param  none
   @return void
*/
template <typename T>
void LinkedQueue<T>::display() {
	Node<T>* current = head;
	for (int i = 0; i < _size; i++) {
		std::cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	std::cout << std::endl;
}

#endif