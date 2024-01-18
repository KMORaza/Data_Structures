#include <iostream>
#include <vector>
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }
    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }
    void printGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
};
int main() {
    Graph myGraph(4);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 3);
    myGraph.printGraph();
    return 0;
}
