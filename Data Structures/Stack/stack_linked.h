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
		int top();

		int size();
		bool empty();

		void clear();
		void display();
};

/*
   Default Constructor
*/
template <typename T>
LinkedStack<T>::LinkedStack() : head(nullptr), _size(0) {}

/*
   Copy Constructor

   @param  other	secondary queue to copy
   @return void
*/
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

/*
   Copy Assignment Operator

   @param  rhs	secondary Queue to copy
   @return void
*/
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

/*
   Destructor
*/
template <typename T>
LinkedStack<T>::~LinkedStack() { clear(); }

/*
   pushes element to back (top) of stack list (head = top)

   @param  data		data of element to be pushed
   @return void
*/
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

/*
   Pops & returns element from top of stack list (newest element) (head = top)

   @param  none
   @return T	value of element that was popped
*/
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

/*
   Returns elements that is currently at top of stack

   @param  none
   @return T	value of element at back of array
*/
template <typename T>
T LinkedStack<T>::top() { return head->data; }

/*
   Obtains size of Stack

   @param  none
   @return int	returns _size attribute
*/
template <typename T>
int LinkedStack<T>::size() { return _size; }

/*
   Checks if Stack is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool LinkedStack<T>::empty() { 
	if (_size == 0) 
		return true;
	return false;
}

/*
   Clears stack, same as clearing a linked list (node by node)

   @param  none
   @return void
*/
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

/*
   Displays Stack seperated by arrows

   @param  none
   @return void
*/
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