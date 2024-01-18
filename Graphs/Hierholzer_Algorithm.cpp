#include <iostream>
#include <vector>
#include <stack>
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void hierholzerAlgorithm();
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    std::stack<int> circuit;
    void eulerianPath(int startVertex);
};
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}
void Graph::eulerianPath(int startVertex) {
    circuit.push(startVertex);
    while (!circuit.empty()) {
        int currentVertex = circuit.top();
        if (!adjList[currentVertex].empty()) {
            int nextVertex = adjList[currentVertex].back();
            adjList[currentVertex].pop_back();
            circuit.push(nextVertex);
        } else {
            circuit.pop();
        }
    }
}
void Graph::hierholzerAlgorithm() {
    int startVertex = 0;
    for (int i = 0; i < vertices; ++i) {
        if (!adjList[i].empty()) {
            startVertex = i;
            break;
        }
    }
    eulerianPath(startVertex);
    std::cout << "Eulerian Circuit: ";
    while (!circuit.empty()) {
        std::cout << circuit.top() << " ";
        circuit.pop();
    }
    std::cout << std::endl;
}
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.hierholzerAlgorithm();
    return 0;
}
