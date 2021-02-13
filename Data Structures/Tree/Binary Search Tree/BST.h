#ifndef BST_H
#define BST_H

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree {
    private:
        Node* root;
    public:
        BinarySearchTree();
        BinarySearchTree(std::string word);
        BinarySearchTree(const BinarySearchTree &rhs);
        ~BinarySearchTree();

        void insert(int n);
        void remove(int n);
        bool exists(int n) const;

        int findMin();
        int findMax();

        int height(const Node* node);
        int depth(const Node* node);

        std::string inorder() const;
        std::string preorder() const;
        std::string postorder() const;
};

#endif