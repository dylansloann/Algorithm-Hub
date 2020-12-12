#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class Node {
	public:
		int data;
		Node* link;
		// constructors
		Node();
		Node(int value);
};

class List {
	private:
		Node* head;
		Node* tail;
		size_t _size;
	public:
		// constructors/destructor
		List();
		List(const List& other);
		List& operator=(const List& rhs);
		~List();

		// checking and getting size
		bool empty();
		int size();

		// clears list of all nodes
		void clear();

		// single node conditions
		void create_single(Node* node);
		void remove_single();

		// inserting a node
		void push_front(int value);
		void push_back(int value);
		void insert(int value, size_t index);
		bool contains(int value) const;

		// removing a node
		void remove_front();
		void remove_back();
		void remove(size_t index);

		// obtains Node value at front or back
		int front();
		int back();

		// displays list
		void display();
};

#endif