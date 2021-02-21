#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

template <typename T>
class Stack {
	private:
		T* stackArray;
		int capacity;
		int _size;
	public:
		Stack();
		Stack(const Stack& other);
		Stack& operator=(const Stack& rhs);
		~Stack();

		void push(T data);
		T pop();
		T top();

		int size();
		bool empty();

		void display();
};

/*
   Default Constructor
*/
template <typename T>
Stack<T>::Stack() : stackArray(nullptr), capacity(0), _size(0) {} 

/*
   Copy Constructor

   @param  other	secondary queue to copy
*/
template <typename T>
Stack<T>::Stack(const Stack& other) : stackArray(new T[capacity]), capacity(other.capacity), _size(other._size)  {
	for (T i = 0; i < _size; i++) {
		stackArray[i] = other.stackArray[i];
	}
}

/*
   Copy Assignment Operator

   @param  rhs	secondary Queue to copy
   @return Stack<T>& 	refrence to stack once fully copied
*/
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {
	if (stackArray == rhs.stackArray) {return *this;}

	delete [] stackArray;

	capacity = rhs.capacity;
	_size = rhs._size;
	stackArray = new T[capacity];

	for (int i = 0; i < _size; i++) {
		stackArray[i] = rhs.stackArray[i];
	}

	return *this;
}

/*
   Destructor
*/
template <typename T>
Stack<T>::~Stack() { delete [] stackArray; }

/*
   pushes element to back (top) of stack array

   @param  data		data of element to be pushed
   @return void
*/
template <typename T>
void Stack<T>::push(T data) {
	// doubles capacity if stack is full
	if (_size == capacity) {
		if (capacity == 0) capacity = 1;
		capacity *= 2;
		T* doubledStackArray = new T[capacity];
		for (int i = 0; i < _size; i++) { 
			doubledStackArray[i] = stackArray[i]; 
		}
		delete [] stackArray;
		stackArray = doubledStackArray;
	}

	stackArray[_size] = data;
	_size++;
}

/*
   Pops & returns element from top of stack (newest element)

   @param  none
   @return T	value of element that was popped
*/
template <typename T>
T Stack<T>::pop() { 
	if (empty()) { throw std::logic_error("Popping from empty stack"); }
	_size--;
	return stackArray[_size];
}

/*
   Returns elements that is currently at top of stack

   @param  none
   @return T	value of element at back of array
*/
template <typename T>
T Stack<T>::top() { return stackArray[_size - 1]; }

/*
   Obtains size of Stack

   @param  none
   @return int	returns _size attribute
*/
template <typename T>
T Stack<T>::size() { return _size; }

/*
   Checks if Stack is empty

   @param  none
   @return bool		return true if empty
*/
template <typename T>
bool Stack<T>::empty() { 
	if (_size == 0) return true;
	return false;
}

/*
   Displays Stack seperated by spaces

   @param  none
   @return void
*/
template <typename T>
void Stack<T>::display() {
	for (int i = 0; i < _size; i++) {
		std::cout << stackArray[i] << " ";
	}
	std::cout << std::endl;
}

#endif