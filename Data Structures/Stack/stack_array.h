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
		T peek();

		int size();
		bool empty();

		void display();
};

template <typename T>
Stack<T>::Stack() : stackArray(nullptr), capacity(0), _size(0) {} 

template <typename T>
Stack<T>::Stack(const Stack& other) : stackArray(new T[capacity]), capacity(other.capacity), _size(other._size)  {
	for (T i = 0; i < _size; i++) {
		stackArray[i] = other.stackArray[i];
	}
}

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

template <typename T>
Stack<T>::~Stack() { delete [] stackArray; }

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

template <typename T>
int Stack<T>::pop() { 
	if (empty()) { throw std::logic_error("Popping from empty stack"); }
	_size--;
	return stackArray[_size];
}

template <typename T>
T Stack<T>::peek() { return stackArray[_size - 1]; }

template <typename T>
T Stack<T>::size() { return _size; }

template <typename T>
bool Stack<T>::empty() { 
	if (_size == 0) return true;
	return false;
}

template <typename T>
void Stack<T>::display() {
	for (int i = 0; i < _size; i++) {
		std::cout << stackArray[i] << " ";
	}
	std::cout << std::endl;
}

#endif