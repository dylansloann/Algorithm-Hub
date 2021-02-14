#include "BST.h"
#include <iostream>

// ================== Node ==================

Node::Node() : data(0), left(nullptr), right(nullptr) {}

Node::Node(int data) : data(data), left(nullptr), right(nullptr) {}


// =========== Binary Search Tree ============

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(int data) : root(new Node(data)) {}

~BinarySearchTree::BinarySearchTree() { clear(); }