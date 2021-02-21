#ifndef GRAPH_ADJ_LIST_H
#define GRAPH_ADJ_LIST_H

#include <vector>
using std::vector;

struct GraphNode {
    int data;
    GraphNode* next;

    GraphNode(int data) : data(data), next(nullptr) {};
    GraphNode(int data, GraphNode* next) : data(data), next(next) {};
};

class GraphAdjList {
    private:
        vector<GraphNode*> adjList;
        bool directed;
    public:
        GraphAdjList(int val, bool directed);
        ~GraphAdjList();

        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);

        void addVertex(int dest);
        void removeVertex(int val);
        int getNumVertices();

        void clear();
        void print();
};


/*
   Parameterized Constructor

   @param  val	secondary linked list to copy
   @param  directed	 bool signifying if graph is directed
*/
GraphAdjList::GraphAdjList(int val, bool directed) : adjList(vector<GraphNode*>(val)), directed(directed)  {}

/*
   Destructor
*/
GraphAdjList::~GraphAdjList() { clear(); }

/*
   Add edge between two nodes (add to src & dest list)

   @param  src   integer signifying src node
   @param  dest  integer signifying desitination node
   @return void
*/
void GraphAdjList::addEdge(int src, int dest) {
    if (src > adjList.size() || dest > adjList.size())
        throw std::invalid_argument("Out of range.");
    
    GraphNode* srcNode = new GraphNode(dest, adjList[src]);
    adjList[src] = srcNode;

    if (!directed) {
        GraphNode* destNode = new GraphNode(src, adjList[dest]);
        adjList[dest] = destNode;
    }
}

/*
   Remove edge between two nodes (remove from src & dest list)

   @param  src   integer signifying src node
   @param  dest  integer signifying desitination node
   @return void
*/
void GraphAdjList::removeEdge(int src, int dest) {
    if (src > adjList.size() || dest > adjList.size())
        throw std::invalid_argument("Out of range.");
    else if (adjList[src] == nullptr) 
        throw std::invalid_argument("No edges at src.");
    
    // deletetion on src list
    GraphNode* current = adjList[src];
    GraphNode* prev = nullptr;

    while (current->next != nullptr && current->data != dest) {
        current = current->next;
        prev = current;
    }

    if (current->data == dest) {
        if (adjList[src]->next == nullptr)
            adjList[src] = nullptr;
        if (prev != nullptr)
            prev->next = current->next;
        delete current;
    }

    if (directed) {
        // deletetion on dest list
        current = adjList[dest];
        prev = nullptr;

        while (current->next != nullptr && current->data != src) {
            current = current->next;
            prev = current;
        }

        if (current->data == src) {
            if (adjList[dest]->next == nullptr)
                adjList[dest] = nullptr;
            if (prev != nullptr)
                prev->next = current->next;
            delete current;
        }
    }
}

/*
   Add vertex to graph (add additional linked list)

   @param  dest  integer signifying desitination node of newly added node
   @return void
*/
void GraphAdjList::addVertex(int dest) {
    adjList.push_back(new GraphNode(dest, nullptr));
}

/*
   Remove vertex from graph (erase linked list inside vector)

   @param  val  integer signifying node to clear
   @return void
*/
void GraphAdjList::removeVertex(int val) {
    if (val > adjList.size())
        throw std::invalid_argument("Out of range.");
    
    GraphNode* current;
    GraphNode* prev;
    for (int i = 0; i < adjList.size(); i++) {
        current = adjList[i];
        while (current != nullptr) {
            if (current->data == val) {
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
    
    current = adjList[val];
    GraphNode* tmp;
    while (current != nullptr) {
        tmp = current->next;
        delete current;
        current = tmp;
    }
    adjList.erase(adjList.begin() + val);
}

/*
   Obtains number of vertices in Graph

   @param  none
   @return int  size of vector holding linked list
*/
int GraphAdjList::getNumVertices() { return adjList.size(); }

/*
   Deollcates all linked list contained in the vector (entirty of graph)

   @param  none
   @return void
*/
void GraphAdjList::clear() {
    GraphNode* current;
    GraphNode* tmp;
    for (int i = 0; i < adjList.size(); i++) {
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
void GraphAdjList::print() {
    GraphNode* tmp;
    for (int i = 0; i < adjList.size(); i++) {
        tmp = adjList[i];
        std::cout << "NODE " << i << ":  ";
        while (tmp != nullptr) {
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}

#endif
