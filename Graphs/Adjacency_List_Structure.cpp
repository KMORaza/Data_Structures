#include <iostream>
#include <list>
#include <iterator>
class AdjacencyListGraph {
private:
    int numVertices;
    std::list<int>* adjacencyList;
public:
    AdjacencyListGraph(int vertices) : numVertices(vertices) {
        adjacencyList = new std::list<int>[numVertices];
    }
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src); 
    }
    void printAdjacencyList() const {
        std::cout << "Adjacency List of the graph:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << " -> ";
            std::copy(adjacencyList[i].begin(), adjacencyList[i].end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        }
    }
    ~AdjacencyListGraph() {
        delete[] adjacencyList;
    }
};
int main() {
    AdjacencyListGraph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    graph.printAdjacencyList();
    return 0;
}
