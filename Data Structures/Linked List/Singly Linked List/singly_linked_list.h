#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class Node {
	public:
		int data;
		Node* link;
		// constructors
		Node();
		Node(int value);
};

class SinglyLinkedList {
	private:
		Node* head;
		Node* tail;
		int _size;
	public:
		// constructors/destructor
		SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList& other);
		SinglyLinkedList& operator=(const SinglyLinkedList& rhs);
		~SinglyLinkedList();

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
		void insert(int value, int index);
		bool contains(int value);

		// removing a node
		void remove_front();
		void remove_back();
		void remove(int index);

		// reversing the list
		void reverse();

		// obtains Node at front or back
		const Node* front();
		const Node* back();

		// displays list
		void display();
};

#endif