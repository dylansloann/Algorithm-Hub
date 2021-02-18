#ifndef BST_H
#define BST_H

#include <queue>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
    private:
        Node<T>* root;
    public:
        BinarySearchTree();
        BinarySearchTree(T data);
        ~BinarySearchTree();

        Node<T>* insert(Node<T>* node, T n);
        void remove(Node<T>* node, T n);
        Node<T>* find(Node<T>* node, T n) const;

        int findMin() const;
        int findMax() const;
        int height(const Node<T>* node) const;

        void clear(Node<T>* node);

        void inorder(Node<T>* node);
        void preorder(Node<T>* node);
        void postorder(Node<T>* node);
        void BFS(Node<T>* node);



        // pre root paramter methods for recursive methods
        void insert(T n) { 
            if (root == nullptr) {
                root = new Node<T>(n);
                root->left = nullptr;
                root->right = nullptr;
                return;
            }
            insert(root, n);
        }
        void remove(T n) { remove(root, n); }
        Node<T>* find(T n) const { return find(root, n); }

        int height() const { return height(root); }
        void clear() { clear(root); }
        
        void inorder() { inorder(root); }
        void preorder() { preorder(root); }
        void postorder() { postorder(root); }
        void BFS() { BFS(root); }
};




template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T data) : root(new Node<T>(data)) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() { clear(root); }

template <typename T>
Node<T>* BinarySearchTree<T>::insert(Node<T>* node, T n) {
    if (node == nullptr) {
        node = new Node<T>;
        node->data = n;
        node->left = nullptr;
        node->right = nullptr;
    }
    
    else if (n > node->data)
        node->right = insert(node->right, n);
    else
        node->left = insert(node->left, n);

    return node;
}

template <typename T>
void BinarySearchTree<T>::remove(Node<T>* node, T n) {
    if (node == nullptr)
        return;
 
    if (n < node->n)
        root->left = deleteNode(node->left, n);
    else if (n > node->n)
        node->right = deleteNode(node->right, n);


    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    }
    else if(root->right == nullptr) {
        Node<T>* tmp = node;
        node = node->left;
        delete tmp;
    }
    else if(node->left == nullptr) {
        Node<T>* tmp = node;
        node = node->right;
        delete tmp;
    }
    else {
        Node<T>* tmp = minValueNode(root->right);
        root->key = tmp->key;
        root->right = deleteNode(root->right, tmp->key);
    }
}

template <typename T>
Node<T>* BinarySearchTree<T>::find(Node<T>* node, T n) const {
    if (node == nullptr) 
        return nullptr;
    else if (n > node->data)
        find(node->right, n);
    else if (n < node->data)
        find(node->left, n);
    else
        return node;
}

template <typename T>
int BinarySearchTree<T>::findMin() const {
    Node<T>* node = root;
    while (node->left != nullptr)
        node = node->left;
    return node->data;
}

template <typename T>
int BinarySearchTree<T>::findMax() const {
    Node<T>* node = root;
    while (node->right != nullptr)
        node = node->left;
    return node->data;
}

template <typename T>
int BinarySearchTree<T>::height(const Node<T>* node) const {
    if (node == nullptr)
        return 0;

    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    
    if (leftDepth > rightDepth) 
        return leftDepth + 1; 
    else 
        return rightDepth + 1;
}

template <typename T>
void BinarySearchTree<T>::clear(Node<T>* node) {
    if (node == nullptr)
        return;

    clear(node->left);
    clear(node->right);
 
    delete node;
    node = nullptr;
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* node) {
    if (node == nullptr)
        return;

    inorder( node->left );
    std::cout <<  node->data << " -> ";
    inorder( node->right );
}

template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* node) {
    if (node == nullptr)
        return;

    std::cout << node->data << " -> ";
    preorder( node->left );
    preorder( node->right );
}

template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* node) {
    if (node == nullptr)
        return;

    postorder( node->left );
    postorder( node->right );
    std::cout <<  node->data << " -> ";
}

template <typename T>
void BinarySearchTree<T>::BFS(Node<T>* node) {
    if (node != nullptr) {
        std::queue<Node<T>*> order;
        order.push(node);

        while(order.empty() == false) {
            Node<T>* tmp = order.front();
            std::cout << tmp->data << " -> ";
            if (tmp->left != nullptr)
                order.push(tmp->left);
            if (tmp->right != nullptr)
                order.push(tmp->right);
            order.pop();
        }
    }
}

#endif