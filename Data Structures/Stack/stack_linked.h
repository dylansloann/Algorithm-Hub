#ifndef STACK_LINKED_H
#define STACK_LINKED_H

template <typename T>
class Node {
	public:
		T data;
		Node* link;
		Node() : data(0), link(nullptr) {}
		Node(int value) : data(value), link(nullptr) {}
};

template <typename T>
class LinkedStack {
	private:
		Node<T>* head;
		int _size;
	public:
		LinkedStack();
		LinkedStack (const LinkedStack& other);
		LinkedStack& operator=(const LinkedStack& rhs);
		~LinkedStack();

		void push(T data);
		int pop();
		int peek();

		int size();
		bool empty();

		void clear();
		void display();
};


template <typename T>
LinkedStack<T>::LinkedStack() : head(nullptr), _size(0) {}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) : head(new Node<T>(other.head->data)), _size(other._size) {
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
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& rhs) {
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
LinkedStack<T>::~LinkedStack() { clear(); }

template <typename T>
void LinkedStack<T>::push(T data) {
	Node<T>* node = new Node<T>(data);
	
	if (empty()) { 
		head = node;
		node->link = nullptr;
		_size = 1;
		return;
	}

	else {
		node->link = head;
		head = node;
		_size++;
	}
}

template <typename T>
T LinkedStack<T>::pop() { 
	T returnVal = head->data;

	if (empty()) { throw std::logic_error("Popping from empty stack"); }

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
T LinkedStack<T>::peek() { return head->data; }

template <typename T>
int LinkedStack<T>::size() { return _size; }

template <typename T>
bool LinkedStack<T>::empty() { 
	if (_size == 0) 
		return true;
	return false;
}

template <typename T>
void LinkedStack<T>::clear() {
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
void LinkedStack<T>::display() {
	Node<T>* current = head;
	for (int i = 0; i < _size; i++) {
		std::cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	std::cout << std::endl;
}

#endif