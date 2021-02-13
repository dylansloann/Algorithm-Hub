#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class Node {
	public:
		int data;
		Node* link;
		Node();
		Node(int value);
};

class SinglyLinkedList {
	private:
		Node* head;
		Node* tail;
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

		void reverse();

		const Node* front();
		const Node* back();

		void display();
};

#endif