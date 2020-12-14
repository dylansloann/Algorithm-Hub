#include "queue_linked.h"
#include <iostream>

using std::cin, std::cout, std::endl;

// ================== Node ==================

// default constructor
Node::Node() : data(0), link(nullptr) {}

// constructor with value
Node::Node(int value) : data(value), link(nullptr) {}



// ================== Linked Stack ==================

// default constructor
Queue::Queue() : queueArray(new int[2]), capacity(2), length(0), front(-1), back(-1) {}