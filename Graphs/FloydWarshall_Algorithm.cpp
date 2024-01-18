#include <iostream>
#include <vector>
const int INF = INT_MAX;
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, INF));
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i][i] = 0;
        }
    }
    void addEdge(int u, int v, int weight) {
        adjacencyMatrix[u][v] = weight;
    }
    void floydWarshall() {
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (adjacencyMatrix[i][k] != INF && adjacencyMatrix[k][j] != INF &&
                        adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j]) {
                        adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                    }
                }
            }
        }
        std::cout << "Shortest distances between all pairs of vertices:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] == INF) {
                    std::cout << "INF ";
                } else {
                    std::cout << adjacencyMatrix[i][j] << " ";
                }
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
    myGraph.addEdge(0, 1, 5);
    myGraph.addEdge(0, 3, 10);
    myGraph.addEdge(1, 2, 3);
    myGraph.addEdge(2, 3, 1);
    myGraph.floydWarshall();
    return 0;
}
