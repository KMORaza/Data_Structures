#include <iostream>
#include <vector>
#include <unordered_set>
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(numVertices);
    }
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }
    void depthFirstSearch(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::cout << "Depth-First Search starting from vertex " << startVertex << ": ";
        dfsRecursive(startVertex, visited);
        std::cout << std::endl;
    }
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
    void dfsRecursive(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }
};
int main() {
    Graph myGraph(5);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(3, 4);
    myGraph.depthFirstSearch(0);
    return 0;
}
