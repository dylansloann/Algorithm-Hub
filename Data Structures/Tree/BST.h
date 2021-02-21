#ifndef BST_H
#define BST_H

#include <queue>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
    int getData() { return data; }
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
        Node<T>* remove(Node<T>* node, T n);
        Node<T>* find(Node<T>* node, T n) const;

        Node<T>* findMin(Node<T>* node) const;
        Node<T>* findMax(Node<T>* node) const;
        int height(const Node<T>* node) const;

        Node<T>* clear(Node<T>* node);

        void inorder(Node<T>* node);
        void preorder(Node<T>* node);
        void postorder(Node<T>* node);
        void BFS(Node<T>* node);



        // pre root methods for paramaterized recursive methods
        Node<T>* insert(T n) { return insert(root, n); }
        Node<T>* remove(T n) { return remove(root, n); }
        Node<T>* find(T n) const { return find(root, n); }

        Node<T>* findMin() const { return findMin(root); }
        Node<T>* findMax() const { return findMax(root); }
        int height() const { return height(root); }
        void clear() { clear(root); root = nullptr; }
        
        void inorder() { inorder(root); }
        void preorder() { preorder(root); }
        void postorder() { postorder(root); }
        void BFS() { BFS(root); }
};



/*
   Default Constructor
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

/*
   Paramaterized Constructor

   @param  data	    data to assign to new root node
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T data) : root(new Node<T>(data)) {}

/*
   Destructor
*/
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() { clear(root); }

/*
   Inserts element at correct posotion in tree

   @param  node	    node to begin from (usually root)
   @param  n	    value to be inserted
   @return Node<T>*    node that was inserted 
*/
template <typename T>
Node<T>* BinarySearchTree<T>::insert(Node<T>* node, T n) {
    if (node == nullptr) {
        node = new Node<T>;
        node->data = n;
        node->left = nullptr;
        node->right = nullptr;
        if (root == nullptr)
            root = node;
    }
    
    else if (n > node->data)
        node->right = insert(node->right, n);
    else
        node->left = insert(node->left, n);

    return node;
}

/*
   Removes element from tree and readjust accordingly

   @param  node	    node to begin from (usually root)
   @param  n	    value to be removed
   @return Node<T>*     node that was deleted
*/
template <typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* node, T n) {
    if (node == nullptr)
        return node;
 
    if (n < node->data)
        node->left = remove(node->left, n);
    else if (n > node->data)
        node->right = remove(node->right, n);

    else {

        if (node->left == nullptr && node->right == nullptr) {
            std::cout << "test" << std::endl;
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
            Node<T>* tmp = findMin(node->right);
            node->data = tmp->data;
            node->right = remove(node->right, tmp->data);
        }
    
    }

    return node;
}

/*
   Searches for element inside tree by recursion and comparison

   @param  node	    node to begin from (usually root)
   @param  n	    value to be found
   @return Node<T>*    node that was found / (nullptr if not)
*/
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

/*
   Finds minimum element in Tree iteratively

   @param  none
   @return Node<T>*    minimum Node
*/
template <typename T>
Node<T>* BinarySearchTree<T>::findMin(Node<T>* node) const {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

/*
   Finds maximum element in Tree iteratively

   @param  none
   @return Node<T>*    maximum node
*/
template <typename T>
Node<T>* BinarySearchTree<T>::findMax(Node<T>* node) const {
    while (node->right != nullptr)
        node = node->right;
    return node;
}

/*
   Calcalates height of tree from given node

   @param  node	    node to caculate height
   @return int    height of tree
*/
template <typename T>
int BinarySearchTree<T>::height(const Node<T>* node) const {
    if (node == nullptr)
        return 0;

    int leftDepth = height(node->left);
    int rightDepth = height(node->right);
    
    if (leftDepth > rightDepth) 
        return leftDepth + 1; 
    else 
        return rightDepth + 1;
}

/*
   Clears tree from root node recursively

   @param  node	  root node
   @return void
*/
template <typename T>
Node<T>* BinarySearchTree<T>::clear(Node<T>* node) {
    if (node == nullptr)
        return nullptr;

    node->left = clear(node->left);
    node->right = clear(node->right);
 
    delete node;
    return nullptr;
}

/*
   Prints inorder travelsal of given node

   @param  node	  node to begin from (usually root)
   @return void 
*/
template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* node) {
    if (node == nullptr)
        return;

    inorder( node->left );
    std::cout <<  node->data << " -> ";
    inorder( node->right );
}

/*
   Prints preorder travelsal of given node

   @param  node	  node to begin from (usually root)
   @return void 
*/
template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* node) {
    if (node == nullptr)
        return;

    std::cout << node->data << " -> ";
    preorder( node->left );
    preorder( node->right );
}

/*
   Prints postorder travelsal of given node

   @param  node	  node to begin from (usually root)
   @return void 
*/
template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* node) {
    if (node == nullptr)
        return;

    postorder( node->left );
    postorder( node->right );
    std::cout <<  node->data << " -> ";
}

/*
   Prints level order travelsal of given node

   @param  node	  node to begin from (usually root)
   @return void 
*/
template <typename T>
void BinarySearchTree<T>::BFS(Node<T>* node) {
    if (node != nullptr) {
        std::queue<Node<T>*> order;
        order.push(node);

        while(!order.empty()) {
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