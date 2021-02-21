#ifndef GRAPH_ADJ_MATRIX_H
#define GRAPH_ADJ_MATRIX_H

#include <vector>
using std::vector;

class GraphAdjMatrix {
    private:
        vector<vector<bool>> matrix;
        bool directed;
    public:
        GraphAdjMatrix(int val, bool directed);

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
GraphAdjMatrix::GraphAdjMatrix(int val, bool directed) : matrix(vector<vector<bool>>(val)), directed(directed)  {
    for (int i = 0; i < val; i++) {
        matrix[i].resize(10);
    }
}

/*
   Addd edge between two nodes (add to src & dest column & row)

   @param  src   integer signifying src node
   @param  dest  integer signifying desitination node
   @return void
*/
void GraphAdjMatrix::addEdge(int src, int dest) {
    if (src > matrix.size() || dest > matrix.size())
        throw std::invalid_argument("Out of range.");
    
    matrix[src][dest] = true;

    if (!directed) {
        matrix[dest][src] = true;
    }
}

/*
   Remove edge between two nodes (remove from src & dest column & row)

   @param  src   integer signifying src node
   @param  dest  integer signifying desitination node
   @return void
*/
void GraphAdjMatrix::removeEdge(int src, int dest) {
    if (src > matrix.size() || dest > matrix.size())
        throw std::invalid_argument("Out of range.");
    
    matrix[src][dest] = false;

    if (directed) {
        matrix[dest][src] = false;
    }
}

/*
   Add vertex to graph (add additional row & column)

   @param  dest  integer signifying desitination node of newly added node
   @return void
*/
void GraphAdjMatrix::addVertex(int dest) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].push_back(false);
    }
    matrix.push_back(vector<bool>(matrix.size() + 1));
    addEdge(matrix.size() - 1, dest);
}

/*
   Remove vertex from graph (erase column & row indexed at specified value)

   @param  val  integer signifying node to clear
   @return void
*/
void GraphAdjMatrix::removeVertex(int val) {
    for (int i = 0; i < matrix.size(); i++) { 
        matrix[i].erase(matrix[i].begin() + val);
    }
    matrix.erase(matrix.begin() + val);
}

/*
   Obtains number of vertices in Graph

   @param  none
   @return int  size of vector holding linked list
*/
int GraphAdjMatrix::getNumVertices() { return matrix.size(); }

/*
   Resets all values to false

   @param  none
   @return void
*/
void GraphAdjMatrix::clear() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            matrix[i][j] = false;
        }
    }
}

/*
   Prints out Adjacency Matrix represention of graph

   @param  none
   @return void
*/
void GraphAdjMatrix::print() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
