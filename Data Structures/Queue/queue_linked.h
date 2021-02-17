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


template <typename T>
LinkedQueue<T>::LinkedQueue() : _size(0), head(nullptr), tail(nullptr) {}

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

template <typename T>
LinkedQueue<T>::~LinkedQueue() { clear(); }

template <typename T>
void LinkedQueue<T>::enqueue(T data) {
	Node<T>* node = new Node<T>(data);
	
	if (empty()) { 
		head = node;
		tail = node;
		node->link = nullptr;
		_size = 1;
		return;
	}

	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

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

template <typename T>
int LinkedQueue<T>::size() { return _size; }

template <typename T>
bool LinkedQueue<T>::empty() { 
	if (_size == 0) return true; 
	return false;
}

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