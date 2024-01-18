#include <iostream>
#include <queue>
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
    void breadthFirstSearch(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> bfsQueue;
        visited[startVertex] = true;
        bfsQueue.push(startVertex);
        std::cout << "Breadth-First Search starting from vertex " << startVertex << ": ";
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            std::cout << currentVertex << " ";
            bfsQueue.pop();
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};
int main() {
    Graph myGraph(5);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(3, 4);
    myGraph.breadthFirstSearch(0);
    return 0;
}
