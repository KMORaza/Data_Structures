#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    bool isHamiltonianCycle();
private:
    int vertices;
    std::vector<std::list<int>> adjList;
    bool isCycle(std::vector<int>& path, int pos);
    bool isValidNextVertex(int v, int pos, std::vector<int>& path);
};
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}
bool Graph::isHamiltonianCycle() {
    std::vector<int> path(vertices, -1);
    path[0] = 0;
    if (!isCycle(path, 1)) {
        std::cout << "No Hamiltonian cycle exists" << std::endl;
        return false;
    }
    std::cout << "Hamiltonian Cycle exists:" << std::endl;
    for (int vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << path[0] << std::endl;
    return true;
}
bool Graph::isCycle(std::vector<int>& path, int pos) {
    if (pos == vertices) {
        return adjList[path[pos - 1]].end() !=
               std::find(adjList[path[pos - 1]].begin(), adjList[path[pos - 1]].end(), path[0]);
    }
    for (int v : adjList[path[pos - 1]]) {
        if (isValidNextVertex(v, pos, path)) {
            path[pos] = v;
            if (isCycle(path, pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
bool Graph::isValidNextVertex(int v, int pos, std::vector<int>& path) {
    if (std::find(path.begin(), path.end(), v) != path.end()) {
        return false;
    }
    if (!adjList[path[pos - 1]].empty() &&
        std::find(adjList[path[pos - 1]].begin(), adjList[path[pos - 1]].end(), v) == adjList[path[pos - 1]].end()) {
        return false;
    }
    return true;
}
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.isHamiltonianCycle();
    return 0;
}
