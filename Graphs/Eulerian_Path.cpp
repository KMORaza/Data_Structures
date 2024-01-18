#include <iostream>
#include <vector>
#include <stack>
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    bool hasEulerianPath();
    void findEulerianPath(int startVertex);
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    std::vector<int> inDegree, outDegree;
    bool isConnected();
    int countOddDegreeVertices();
    void dfs(int vertex, std::stack<int>& path);
};
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
    inDegree.resize(vertices, 0);
    outDegree.resize(vertices, 0);
}
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    outDegree[v]++;
    inDegree[w]++;
}
bool Graph::isConnected() {
    std::vector<bool> visited(vertices, false);
    int count = 0; 
    for (int i = 0; i < vertices; ++i) {
        if (!adjList[i].empty()) {
            dfs(i, visited);
            count++;
            break;
        }
    }
    for (int i = 0; i < vertices; ++i) {
        if (!adjList[i].empty() && !visited[i]) {
            return false; 
        }
    }
    return count == 1;
}
int Graph::countOddDegreeVertices() {
    int count = 0;
    for (int i = 0; i < vertices; ++i) {
        if ((inDegree[i] + outDegree[i]) % 2 != 0) {
            count++;
        }
    }
    return count;
}
void Graph::dfs(int vertex, std::stack<int>& path) {
    path.push(vertex);
    for (int neighbor : adjList[vertex]) {
        if (!path.empty() && path.top() == neighbor) {
            path.pop();
            continue; 
        }
        inDegree[neighbor]--;
        outDegree[vertex]--;
        dfs(neighbor, path);
    }
}
bool Graph::hasEulerianPath() {
    if (!isConnected() || countOddDegreeVertices() != 2) {
        return false;
    }
    return true;
}
void Graph::findEulerianPath(int startVertex) {
    if (!hasEulerianPath()) {
        std::cout << "The graph does not have an Eulerian path." << std::endl;
        return;
    }
    std::stack<int> path;
    dfs(startVertex, path);
    std::cout << "Eulerian Path:";
    while (!path.empty()) {
        std::cout << " " << path.top();
        path.pop();
    }
    std::cout << std::endl;
}
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 1);
    g.addEdge(6, 3);
    g.findEulerianPath(0);
    return 0;
}
