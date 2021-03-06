#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node* next;
		Node* prev;
		Node(T data = 0) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;
		int _size;
	public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList& other);
		DoublyLinkedList& operator=(const DoublyLinkedList& rhs);
		~DoublyLinkedList();

		void push_front(T value);
		void push_back(T value);
		void insertBefore(T value, Node<T>* node);
		void insertAfter(T value, Node<T>* node);
		void insert(T value, int index);

		void removeFront();
		void removeBack();
		void removeBefore(Node<T>* node);
		void removeAfter(Node<T>* node);
		void remove(int index);

		Node<T>* getNode(int index);

		bool empty();
		int size();

		void clear();
		void display();
};


/*
   Default Constructor
*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}

/*
   Copy Constructor

   @param  other	secondary linked list to copy
*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(new Node<T>(other.head->data)), tail(nullptr),  _size(other._size) {
	if (other.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return; }

	Node<T>* current = head;
	Node<T>* tmp = other.head;
	tmp.prev = nullptr;

	while (tmp->next != nullptr) {
		Node<T>* node = new Node<T>(tmp->next->data);
		current->next = node;
		node->prev = current;
		current = current->next;
		tmp = tmp->next;
	}
	
	tail = current;
}

/*
   Copy Assignment Operator

   @param  rhs	secondary linked list to copy
   @return DoublyLinkedList<T>& 	refrence to list once fully copied
*/
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs) {
	if (head == rhs.head) { return *this; }
	else if (rhs.head == nullptr) { head = nullptr; tail = nullptr; _size = 0; return *this; }

	clear();

	head = new Node<T>(rhs.head->data);
	Node<T>* current = head;
	Node<T>* tmp = rhs.head;
	tmp.prev = nullptr;

	while (tmp->next != nullptr) {
		Node<T>* node = new Node<T>(tmp->next->data);
		current->next = node;
		node->prev = current;
		current = current->next;
		tmp = tmp->next;
	}
	
	_size = rhs._size;
	tail = current;

	return *this;
}

/*
   Destructor
*/
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { clear(); }

/*
   Inserts element at front of List

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::push_front(T value) {
    Node<T>* node = new Node<T>(value);

    if ( empty() ) {
		head = node;
		tail = node;
		node->next = nullptr;
		node->prev = nullptr;
		_size = 1;
    }

    else { 
		head->prev = node;
		node->next = head;
		head = node;
		_size++;
    }
}

/*
   Inserts element at back of List

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::push_back(T value) {
	Node<T>* node = new Node<T>(value);

	if ( empty() ) {
		head = node;
		tail = node;
		node->prev = nullptr;
		_size = 1;
	}

	else { 
		node->prev = tail;
		tail->next = node;
		tail = node;
		_size++;
	}

	node->next = nullptr;
}

/*
   Inserts element at before certain node

   @param  inputNode	Node to insert element before
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::insertBefore(T value, Node<T>* inputNode) {
	Node<T>* node = new Node<T>(value);

	if (head == inputNode) { head = node; }
	else { inputNode->prev->next = node; }

	node->prev = inputNode->prev;
	inputNode->prev = node;
	node->next = inputNode;
}

/*
   Inserts element at before certain node

   @param  inputNode	Node to insert element after
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::insertAfter(T value, Node<T>* inputNode) {
	Node<T>* node = new Node<T>(value);

	if (tail == inputNode) { tail = node; }
	else { inputNode->next->prev = node; }

	node->next = inputNode->next;
	inputNode->next = node;
	node->prev = inputNode;
}

/*
   Inserts element at desired index

   @param  value	value of desired insertion
   @param  index	index of desired insertion
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::insert(T value, int index) {
	if (index > _size) { throw std::invalid_argument("Index too large."); }

	else if (index == 0) { push_front(value); }
	else if (index == _size) { push_back(value); }
	else {
		Node<T>* node = new Node<T>(value);
		Node<T>* current = head;
		for (int i = 0; i < _size; i++) {
			if (i == index) {
				current->prev->next = node;
				node->prev = current->prev;
				node->next = current;
				current->prev = node;
				_size++;
				return;
			}
			current = current->next;
		}
	}
}

/*
   Removes element from front of List

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::removeFront() {
	if ( empty() ) { throw std::logic_error("Removing from empty list"); }

	Node<T>* tmp = head;
	head = head->next;
	head->prev = nullptr;
	delete tmp;
	_size--;

	if (_size == 0)
		tail = nullptr;
}

/*
   Removes element from back of List

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::removeBack() {
	if ( empty() ) { throw std::logic_error("Removing from empty list"); }

	Node<T>* tmp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete tmp;
	_size--;

	if (_size == 0)
		head = nullptr;
}

/*
   Removes element at before certain node

   @param  inputNode	Node to remove element before
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::removeBefore(Node<T>* inputNode) {
	if (head == inputNode) { throw std::logic_error("Removing before head"); }
	
	Node<T>* tmp = inputNode->prev;
	if (head->next == inputNode) { head = head->next; }
	else {
		inputNode->prev = inputNode->prev->prev;
		inputNode->prev->next = inputNode;
	}
	delete tmp;
	_size--;
}

/*
   Removes element at after certain node

   @param  inputNode	Node to remove element after
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::removeAfter(Node<T>* inputNode) {
	if (tail == inputNode) { throw std::logic_error("Removing after tail"); }
	
	Node<T>* tmp = inputNode->next;
	if (tail->prev == inputNode) { tail = tail->prev; }
	else {
		inputNode->next = inputNode->next->next;
		inputNode->next->prev = inputNode;
	}
	delete tmp;
	_size--;
}

/*
   Removes element at Index

   @param  index	index of element to be removed
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::remove(int index) {
	if (empty()) { throw std::logic_error("Removing from empty list"); }
	
	else if (index == 0) { removeFront();}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		if (current->next == nullptr)
			tail = current->prev;
		
		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		_size--;
	}
}

/*
   Gets pointer to node at certain index

   @param  index	index of pointer to be retrieved
   @return Node<T>*	pointer of index
*/
template <typename T>
Node<T>* DoublyLinkedList<T>::getNode(int index) {
	Node<T>* tmp = head;
	int i = 0;
	while (tmp->next != nullptr) {
		if (i == index) 
			break;
		tmp = tmp->next;
		i++;
	}

	return tmp;
}

/*
   Obtains size of Linked list

   @param  none
   @return int	returns _size attribute
*/
template <typename T>
int DoublyLinkedList<T>::size() { return _size; }

/*
   Clears Linked List

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::clear() {
	Node<T>* tmp;
	for (int i = 0; i < _size; i++) {
		tmp = head;
		head = head->next;
		delete tmp;
	}

	head = nullptr;
	tail = nullptr;
	_size = 0;
}

/*
   Checks if Linked List is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool DoublyLinkedList<T>::empty() {
	if (_size == 0) return true;
	return false;
}

/*
   Displays Linked List with arrows representing links

   @param  none
   @return void
*/
template <typename T>
void DoublyLinkedList<T>::display() {
	Node<T>* current = head;
	for (int i = 0; i < _size; i++) {
		std::cout << '[' << current->data << ']' << "-->";
		current = current->next;
	}
	std::cout << std::endl;
}

#endif