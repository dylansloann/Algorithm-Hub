#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template <typename T>
class Node {
	public:
		T data;
		Node* link;
		Node() : data(0), link(nullptr) {}
		Node(T data) : data(data), link(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;
		int _size;
	public:
		SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList& other);
		SinglyLinkedList& operator=(const SinglyLinkedList& rhs);
		~SinglyLinkedList();

		bool empty();
		int size();

		void clear();

		// single node conditions
		void create_single(Node<T>* node);
		void remove_single();

		// inserting a node
		void push_front(T value);
		void push_back(T value);
		void insert(T value, int index);
		bool contains(T value);

		// removing a node
		void remove_front();
		void remove_back();
		void remove(int index);

		void reverse();

		const Node<T>* front();
		const Node<T>* back();

		void display();
};


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr),  _size(0) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) : head(new Node<T>(other.head->data)), tail(nullptr),  _size(other._size) {
	if (other.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return; }

	Node<T>* current = head;
	Node<T>* tmp = other.head;

	while (tmp->link != nullptr) {
		Node<T>* node = new Node<T>(tmp->link->data);
		current->link = (node);
		current = current->link;
		tmp = tmp->link;
	}
	
	tail = current;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& rhs) {
	if (head == rhs.head) { return *this; }
	else if (rhs.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return *this; }

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
	tail = current;

	return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }

template <typename T>
bool SinglyLinkedList<T>::empty() { 
	if (_size == 0) 
		return true;
	return false;
}

template <typename T>
int SinglyLinkedList<T>::size() { return _size; }

template <typename T>
void SinglyLinkedList<T>::clear() {
	Node<T>* temp;
	for (int i = 0; i < _size; i++) {
		temp = head;
		head = head->link;
		delete temp;
	}

	head = nullptr;
	tail = nullptr;
	_size = 0;
}

template <typename T>
void SinglyLinkedList<T>::create_single(Node<T>* node) {
	head = node;
	tail = node;
	node->link = nullptr;
	_size = 1;
}

template <typename T>
void SinglyLinkedList<T>::remove_single() {
	delete head;
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

template <typename T>
void SinglyLinkedList<T>::push_front(T value) {
	Node<T>* node = new Node<T>(value);

	if (empty()) { create_single(node); }

	else {
		node->link = head;
		head = node;
		_size++;
	}
}

template <typename T>
void SinglyLinkedList<T>::push_back(T value) {
	Node<T>* node = new Node<T>(value);

	if (empty()) { create_single(node); }

	else {
		tail->link = node;
		tail = node;
		_size++;
	}
}

template <typename T>
void SinglyLinkedList<T>::insert(T value, int index) {
	// error checking
	if (index > _size) { throw std::invalid_argument("Index too large."); }

	else if (index == 0) { push_front(value); return; }
	else if (index == _size) { push_back(value); return; }

	Node<T>* node = new Node<T>(value);

	if (empty()) { create_single(node); }
	
	else {
		Node<T>* current = head;
		Node<T>* previous = head;
		for (int i = 0; i < _size; i++) {
			if (i == index) {
				previous->link = node;
				node->link = current;
				_size++;
				return;
			}
			previous = current;
			current = current->link;
		}
	}
}

template <typename T>
bool SinglyLinkedList<T>::contains(T value) {
	Node<T>* current = head;
	for (int i = 0; i < _size; i++) {
		if (current->data == value) {
			return true;
		}
		current = current->link;
	}

	// if no value was found
	return false;
}

template <typename T>
void SinglyLinkedList<T>::remove_front() {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	else if (_size == 1) { remove_single(); }

	else {
		Node<T>* temp;
		temp = head;
		head = head->link;
		delete temp;
		_size--;
	}
}

template <typename T>
void SinglyLinkedList<T>::remove_back() {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	else if (_size == 1) { remove_single(); return; }

	Node<T>* current = head;
	Node<T>* previous = head;
	while (current != nullptr) {
		previous = current;
		current = current->link;
	}
	delete current;
	tail = previous;
	previous->link = nullptr;
	_size--;
}

template <typename T>
void SinglyLinkedList<T>::remove(int index) {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	else if (_size == 1 && index == 0) { remove_single(); return; }
	else if (index == 0) { remove_front(); return; }

	Node<T>* current = head;
	Node<T>* previous = head;
	for (int i = 0; i < index; i++) {
		previous = current;
		current = current->link;
	}

	// if value is at back
	if (current->link == nullptr) { 
		delete current;
		tail = previous;
		previous->link = nullptr;
	}

	// if value is in middle
	else {
		previous->link = current->link;
		delete current;
	}

	_size--;
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    tail = head;
	Node<T>* current = head;
    Node<T>* previous = nullptr;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

template <typename T>
const Node<T>* SinglyLinkedList<T>::front() { return head; }

template <typename T>
const Node<T>* SinglyLinkedList<T>::back() { return tail; }

template <typename T>
void SinglyLinkedList<T>::display() {
	Node<T>* current = head;
	for (int i = 0; i < _size; i++) {
		std::cout << '[' << current->data << ']' << "-->";
		current = current->link;
	}
	std::cout << std::endl;
}

#endif