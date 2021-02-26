#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H

#include <vector>
#include <queue>
using std::vector, std::queue;

struct EdgeNode {
    int data;
    EdgeNode* next;
    EdgeNode(int data, EdgeNode* next = nullptr) : data(data), next(next) {};
};

template <typename T>
struct Vertex {
    T name;
    int key;

    Vertex(T name, int key) : name(name), key(key) {}
};

template <typename T>
class GraphAdjList {
    private:
        vector<EdgeNode*> adjList;
        vector<Vertex<T>*> vertices;
        bool directed;
        int numVertices;
    public:
        GraphAdjList(int size, bool directed);
        ~GraphAdjList();

        void addEdge(Vertex<T>* src, Vertex<T>* dest);
        void removeEdge(Vertex<T>* src, Vertex<T>* dest);

        void addVertex(T name);
        void removeVertex(T name);
        int getNumVertices();

        Vertex<T>* getVertex(T name);
        Vertex<T>* getVertex(int key);

        void clear();
        void print();

        void DFSHelper(int v, bool visited[]);
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
GraphAdjList<T>::GraphAdjList(int size, bool directed) : adjList(size), vertices(0), directed(directed), numVertices(0) {}

/*
   Destructor
*/
template <typename T>
GraphAdjList<T>::~GraphAdjList() { clear(); }

/*
   Add edge between two nodes (add to src & dest list)

   @param  src   src vertex to obtain data
   @param  dest  dest vertex to obtain data
   @return void
*/
template <typename T>
void GraphAdjList<T>::addEdge(Vertex<T>* src, Vertex<T>* dest) {
    if (src->key > numVertices || dest->key > numVertices)
        throw std::invalid_argument("Out of range.");
    
    EdgeNode* srcNode = new EdgeNode(dest->key, adjList[src->key]);
    adjList[src->key] = srcNode;

    if (!directed) {
        EdgeNode* destNode = new EdgeNode(src->key, adjList[dest->key]);
        adjList[dest->key] = destNode;
    }
}

/*
   Remove edge between two nodes (remove from src & dest list)

   @param  src   src vertex to obtain data
   @param  dest  dest vertex to obtain data
   @return void
*/
template <typename T>
void GraphAdjList<T>::removeEdge(Vertex<T>* src, Vertex<T>* dest) {
    if (src->key > adjList.size() || dest->key > adjList.size())
        throw std::invalid_argument("Out of range.");
    else if (adjList[src->key] == nullptr) 
        throw std::invalid_argument("No edges at src.");
    
    // deletetion on src list
    EdgeNode* current = adjList[src->key];
    EdgeNode* prev = nullptr;

    while (current->next != nullptr && current->data != dest->key) {
        current = current->next;
        prev = current;
    }

    if (current->data == dest->key) {
        if (adjList[src->key]->next == current->next)
            adjList[src->key] = current->next;
        if (prev != nullptr)
            prev->next = current->next;
        delete current;
    }

    if (!directed) {
        // deletetion on dest list
        current = adjList[dest->key];
        prev = nullptr;

        while (current->next != nullptr && current->data != src->key) {
            current = current->next;
            prev = current;
        }

        if (current->data == src->key) {
            if (adjList[dest->key]->next == current->next)
                adjList[dest->key] = current->next;
            if (prev != nullptr)
                prev->next = current->next;
            delete current;
        }
    }
}

/*
   Add vertex to graph (add additional linked list)

   @param  name  name of vertex to obtain
   @return void
*/
template <typename T>
void GraphAdjList<T>::addVertex(T name) {
    Vertex<T>* tmp = new Vertex<T>(name, numVertices);
    vertices.push_back(tmp);
    numVertices++;
    
    if (numVertices > adjList.size()) {
        adjList.push_back(nullptr);
    }
}

/*
   Remove vertex from graph (erase linked list inside vector)

   @param  name  name of vertex to remove
   @return void
*/
template <typename T>
void GraphAdjList<T>::removeVertex(T name) {
    Vertex<T>* tmp = getVertex(name);
    if (tmp == nullptr)
        throw std::invalid_argument("Vertex not found.");
    
    int key = tmp->key;
    delete tmp;
    
    EdgeNode* current;
    EdgeNode* prev;
    for (int i = 0; i < numVertices; i++) {
        current = adjList[i];
        while (current != nullptr) {
            if (current->data == key) {
                if (adjList[i] == current) {
                    adjList[i] = current->next;
                    delete current;
                    current = adjList[i];
                } else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
    
    numVertices--;
    current = adjList[key];
    adjList.erase(adjList.begin() + key);
    while (current != nullptr) {
        prev = current->next;
        delete current;
        current = prev;
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
int GraphAdjList<T>::getNumVertices() { return numVertices; }

/*
   Obtains pointer to vertex given name

   @param  name        name to use in linear search
   @return Vertex<T>*  returns vertex pointer
*/
template <typename T>
Vertex<T>* GraphAdjList<T>::getVertex(T name) {
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
Vertex<T>* GraphAdjList<T>::getVertex(int key) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i]->key == key)
            return vertices[i];
    }
    return nullptr;
}

/*
   Deollcates all linked list contained in the vector (entirty of graph)

   @param  none
   @return void
*/
template <typename T>
void GraphAdjList<T>::clear() {
    for (int i = 0; i < numVertices; i++) {
        delete vertices[i];
    }
    
    EdgeNode* current;
    EdgeNode* tmp;
    for (int i = 0; i < numVertices; i++) {
        current = adjList[i];
        while (current != nullptr) {
            tmp = current->next;
            delete current;
            current = tmp;
        }
    }
}



/*
   Prints out Adjacency List represention of graph

   @param  none
   @return void
*/
template <typename T>
void GraphAdjList<T>::print() {
    std::cout << "Vertex List:  ";
    for (int i = 0; i < numVertices; i++) {
        std::cout << vertices[i]->name << "(" << vertices[i]->key << ") |  ";
    }
    std::cout << std::endl << std::endl << std::endl;

    EdgeNode* tmp;
    for (int i = 0; i < numVertices; i++) {
         tmp = adjList[i];
        std::cout << "|  " << vertices[i]->key << "  |    ";
        while (tmp != nullptr) {
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
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
void GraphAdjList<T>::DFSHelper(int key, bool visited[]) {
    std::cout << key << " -> ";
    visited[key] = true;
 
    EdgeNode* tmp = adjList[key];
    while (tmp != nullptr) {
        if (!visited[tmp->data])
            DFSHelper(tmp->data, visited);
        tmp = tmp->next;
    }
}

/*
   Main function for DFS

   @param  name     name of vertex to start the DFS from
   @return void
*/
template <typename T>
void GraphAdjList<T>::DFS(T name) {
    Vertex<T>* tmp = getVertex(name);
    int key = tmp->key;
    
    bool visited[numVertices - 1] = {};
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
void GraphAdjList<T>::BFSHelper(queue<int>& order, bool visited[], int key) {
    EdgeNode* current;
    while(!order.empty()) {
        key = order.front();
        order.pop();
        current = adjList[key];
        
        std::cout << key << " -> ";

        while (current != nullptr) {
            if (!visited[current->data]) {
                visited[current->data] = true;
                order.push(current->data);
            }
            current = current->next;
        }
    }
}

/*
   Main function for BFS

   @param  name     name of vertex to start the BFS from
   @return void
*/
template <typename T>
void GraphAdjList<T>::BFS(T name) {
    bool visited[numVertices] = {};
    queue<int> order;
    
    Vertex<T>* tmp = getVertex(name);
    int key = tmp->key;
 
    visited[key] = true;
    order.push(key);
    
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
