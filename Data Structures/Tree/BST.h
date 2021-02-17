#ifndef BST_H
#define BST_H

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private:
        Node* root;
    public:
        BinarySearchTree();
        BinarySearchTree(int data);
        ~BinarySearchTree();

        void insert(int n);
        void remove(int n);
        bool exists(int n) const;

        int findMin() const;
        int findMax() const;

        int height(const Node* node) const;
        int depth(const Node* node) const;

        void clear();

        std::string inorder() const;
        std::string preorder() const;
        std::string postorder() const;
};

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(int data) : root(new Node(data)) {}

~BinarySearchTree::BinarySearchTree() { clear(); }

#endif