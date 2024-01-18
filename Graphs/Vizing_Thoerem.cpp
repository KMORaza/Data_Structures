#include <iostream>
#include <vector>
#include <algorithm>
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    int chromaticIndex();
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;
    int getMaxDegree();
};
Graph::Graph(int vertices) : vertices(vertices) {
    adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
}
void Graph::addEdge(int v, int w) {
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1;
}
int Graph::getMaxDegree() {
    int maxDegree = 0;
    for (int i = 0; i < vertices; ++i) {
        int degree = std::count(adjMatrix[i].begin(), adjMatrix[i].end(), 1);
        maxDegree = std::max(maxDegree, degree);
    }
    return maxDegree;
}
int Graph::chromaticIndex() {
    int maxDegree = getMaxDegree();
    if (maxDegree % 2 == 0) {
        return maxDegree;
    } else {
        return maxDegree + 1;
    }
}
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    int chromaticIndex = g.chromaticIndex();
    std::cout << "Chromatic Index: " << chromaticIndex << std::endl;
    return 0;
}
