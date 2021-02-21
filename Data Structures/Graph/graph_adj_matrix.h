#ifndef GRAPH_ADJ_MATRIX_H
#define GRAPH_ADJ_MATRIX_H

#include <vector>
#include <iostream>
#include <queue>
using std::vector, std::queue;

template <typename T>
struct Vertex {
    T name;
    int key;

    Vertex(T name, int key) : name(name), key(key) {}
};

template <typename T>
class GraphAdjMatrix {
    private:
        vector<vector<int>> matrix;
        vector<Vertex<T>*> vertices;
        bool directed;
        int numVertices;
    public:
        GraphAdjMatrix(int val, bool directed);
        ~GraphAdjMatrix();

        void addEdge(Vertex<T>* src, Vertex<T>* dest);
        void removeEdge(Vertex<T>* src, Vertex<T>* dest);

        void addVertex(T name);
        void removeVertex(T name);
        int getNumVertices();

        Vertex<T>* getVertex(T name);
        Vertex<T>* getVertex(int key);

        void clear();
        void print();

        void DFSHelper(int key, bool visited[]);
        void DFS(T name);
        void BFSHelper(queue<int>& order, bool visited[], int key);
        void BFS(T name);
};


/*
   Parameterized Constructor

   @param  size      initial size of vertex vector
   @param  directed	 bool signifying if graph is directed
*/
template <typename T>
GraphAdjMatrix<T>::GraphAdjMatrix(int size, bool directed) : matrix(size), vertices(0), directed(directed), numVertices(0) {
    for (int i = 0; i < size; i++) {
        matrix[i].resize(size);
    }
}

/*
   Destructor
*/
template <typename T>
GraphAdjMatrix<T>::~GraphAdjMatrix() { clear(); }

/*
   Add edge between two nodes (add to src & dest column & row)

   @param  src   src vertex to obtain data
   @param  dest  dest vertex to obtain data
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::addEdge(Vertex<T>* src, Vertex<T>* dest) {
    if (src->key > numVertices || dest->key > numVertices)
        throw std::invalid_argument("Out of range.");
    
    matrix[src->key][dest->key] = 1;

    if (!directed) {
        matrix[dest->key][src->key] = 1;
    }
}

/*
   Remove edge between two nodes (remove from src & dest column & row)

   @param  src   src vertex to obtain data
   @param  dest  dest vertex to obtain data
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::removeEdge(Vertex<T>* src, Vertex<T>* dest) {
    if (src->key > numVertices || dest->key > numVertices)
        throw std::invalid_argument("Out of range.");
    
    matrix[src->key][dest->key] = 0;

    if (!directed) {
        matrix[dest->key][src->key] = 0;
    }
}

/*
   Add vertex to graph (add additional row & column)

   @param  name  name of vertex to obtain
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::addVertex(T name) {
    Vertex<T>* tmp = new Vertex<T>(name, numVertices);
    vertices.push_back(tmp);
    numVertices++;
    
    if (numVertices > matrix.size()) {
        matrix.push_back(vector<int>(numVertices));
        for (int i = 0; i < numVertices - 1; i++) {
            matrix[i].push_back(0);
        }
    }
}

/*
   Remove vertex from graph (erase column & row indexed at specified value)
  
   @param  name  name of vertex to remove
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::removeVertex(T name) {
    Vertex<T>* tmp = getVertex(name);

    if (tmp == nullptr)
        throw std::invalid_argument("Vertex<T> not found.");
    
    int key = tmp->key;
    numVertices--;
    delete tmp;

    matrix.erase(matrix.begin() + key);
    for (int i = 0; i < numVertices; i++) {
        matrix[i].erase(matrix[i].begin() + key);
    }

    vertices.erase(vertices.begin() + key);
    for (int i = key; i < numVertices; i++) {
        vertices[i]->key--;
    }
}

/*
   Obtains number of vertices in Graph

   @param  none
   @return int return numVertices
*/
template <typename T>
int GraphAdjMatrix<T>::getNumVertices() { return numVertices; }

/*
   Obtains pointer to vertex given name

   @param  name        name to use in linear search
   @return Vertex<T>*  returns vertex pointer
*/
template <typename T>
Vertex<T>* GraphAdjMatrix<T>::getVertex(T name) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i]->name == name)
            return vertices[i];
    }
    return nullptr;
}

/*
   Obtains pointer to vertex given name

   @param  name        name to use in linear search
   @return Vertex<T>*  returns vertex pointer
*/
template <typename T>
Vertex<T>* GraphAdjMatrix<T>::getVertex(int key) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i]->key == key)
            return vertices[i];
    }
    return nullptr;
}

/*
   Resets all values to 0 & dellocates vertices array

   @param  none
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::clear() {
    for (int i = 0; i < numVertices; i++) {
        delete vertices[i];
    }
    delete[] vertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

/*
   Prints out Adjacency Matrix represention of graph

   @param  none
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::print() {
    std::cout << "Vertex<T> List:  ";
    for (int i = 0; i < numVertices; i++) {
        std::cout << vertices[i]->name << "(" << vertices[i]->key << ") |  ";
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "        ";
    for (int i = 0; i < numVertices; i++) {
        std::cout << "     " << vertices[i]->key << " ";
    }
    std::cout << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "|  " << vertices[i]->key << "  |";
        for (int j = 0; j < numVertices; j++) {
            printf("%7d", matrix[j][i]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/*
   Recursion for DFS

   @param  key      key to dfs from
   @param  visited  array of visited keys
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::DFSHelper(int key, bool visited[]) { 
    std::cout << key << " "; 
    visited[key] = true; 

    for (int i = 0; i < numVertices; i++) { 
        if (matrix[key][i] == 1 && (!visited[i])) { 
            DFSHelper(i, visited); 
        } 
    } 
} 

/*
   Main function for DFS

   @param  name     name of vertex to start the DFS from
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::DFS(T name) { 
    Vertex<T>* tmp = getVertex(name);
    int key = tmp->key;
    bool visited[numVertices] = {}; 
    DFSHelper(key, visited);

    // for disconnected vertices
    for (int i = 0; i < numVertices; i++) {
        if (visited[i] == false) {
            DFSHelper(i, visited);
        }
    }
}

/*
   opertaion for BFS

   @param  order    refrence to order queue
   @param  visited  array of visited keys
   @param  key      key to bfs from
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::BFSHelper(queue<int>& order, bool visited[], int key) {
    while (!order.empty()) {
        key = order.front();
        std::cout << key << " ";
        order.pop();
        for (int i = 0; i < numVertices; i++) {
            if (matrix[key][i] == 1 && (!visited[i])) {
                order.push(i);
                visited[i] = true;
            }
        }
    }
}

/*
   Main function for BFS

   @param  name     name of vertex to start the BFS from
   @return void
*/
template <typename T>
void GraphAdjMatrix<T>::BFS(T name) {
    bool visited[numVertices] = {}; 
    queue<int> order;
    
    Vertex<T>* tmp = getVertex(name);
    int key = tmp->key;
 
    visited[key] = true;
    order.push(key);

    visited[key] = true;

    BFSHelper(order, visited, key);

    // for disconnected vertices
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            order.push(i);
            visited[i] = true;
            BFSHelper(order, visited, i);
        }
    }
}

#endif
