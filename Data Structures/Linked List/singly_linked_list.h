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

/*
   Default Constructor
*/
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr),  _size(0) {}

/*
   Copy Constructor

   @param  other	secondary linked list to copy
   @return void
*/
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

/*
   Copy Assignment Operator

   @param  rhs	secondary linked list to copy
   @return void
*/
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

/*
   Destructor
*/
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }

/*
   Checks if Linked List is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool SinglyLinkedList<T>::empty() { 
	if (_size == 0) return true;
	return false;
}

/*
   Obtains size of Linked list

   @param  rhs	secondary linked list to copy
   @return int	returns _size attribute
*/
template <typename T>
int SinglyLinkedList<T>::size() { return _size; }

/*
   Clears Linked List

   @param  none
   @return void
*/
template <typename T>
void SinglyLinkedList<T>::clear() {
	Node<T>* tmp;
	for (int i = 0; i < _size; i++) {
		tmp = head;
		head = head->link;
		delete tmp;
	}

	head = nullptr;
	tail = nullptr;
	_size = 0;
}

/*
   Creates Linked List of single elements

   @param  node		Node to be created from
   @return void
*/
template <typename T>
void SinglyLinkedList<T>::create_single(Node<T>* node) {
	head = node;
	tail = node;
	node->link = nullptr;
	_size = 1;
}

/*
   Removes from Linked List of single elment (clears)

   @param  none
   @return void
*/
template <typename T>
void SinglyLinkedList<T>::remove_single() {
	delete head;
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

/*
   Inserts element from back of List

   @param  none
   @return void
*/
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

/*
   Inserts element from back of List

   @param  none
   @return void
*/
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

/*
   Inserts element at desired index

   @param  value	value of desired insertion
   @param  index	index of desired insertion
   @return void
*/
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

/*
   Chcek is list contains paramterized value

   @param  value	value to check for containment
   @return void
*/
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

/*
   Removes element from front of List

   @param  none
   @return void
*/
template <typename T>
void SinglyLinkedList<T>::remove_front() {
	if (empty()) { throw std::logic_error("Removing from empty list"); }

	else if (_size == 1) { remove_single(); }

	else {
		Node<T>* tmp;
		tmp = head;
		head = head->link;
		delete tmp;
		_size--;
	}
}

/*
   Removes element from back of List

   @param  none
   @return void
*/
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

/*
   Removes element at Index

   @param  index	index of element to be removed
   @return void
*/
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

/*
   Reverses Linked List

   @param  none
   @return void
*/
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

/*
   Returns Front node

   @param  none
   @return Node<T>*	node at front of list
*/
template <typename T>
const Node<T>* SinglyLinkedList<T>::front() { return head; }

/*
   Returns Back node

   @param  none
   @return Node<T>*	node at back of list
*/
template <typename T>
const Node<T>* SinglyLinkedList<T>::back() { return tail; }

/*
   Copy Assignment Operator

   @param  rhs	secondary linked list to copy
   @return void
*/
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