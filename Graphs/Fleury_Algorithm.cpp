#include <iostream>
#include <vector>
#include <algorithm>
class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void fleuryAlgorithm();
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    bool isValidNextEdge(int v, int w);
    void removeEdge(int v, int w);
    void dfs(int v);
};
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}
bool Graph::isValidNextEdge(int v, int w) {
    int countV = std::count_if(adjList[v].begin(), adjList[v].end(),
                               [](int neighbor) { return neighbor != -1; });

    if (countV == 1) {
        return true;
    }
    std::vector<bool> visited(vertices, false);
    int count1 = 0;
    dfs(v);
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && !adjList[i].empty()) {
            count1++;
            break;
        }
    }
    removeEdge(v, w);
    std::fill(visited.begin(), visited.end(), false);
    int count2 = 0;
    dfs(v);
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && !adjList[i].empty()) {
            count2++;
            break;
        }
    }
    addEdge(v, w);
    return (count1 > count2) ? false : true;
}
void Graph::removeEdge(int v, int w) {
    auto it = std::find(adjList[v].begin(), adjList[v].end(), w);
    *it = -1;
    it = std::find(adjList[w].begin(), adjList[w].end(), v);
    *it = -1;
}
void Graph::dfs(int v) {
    if (adjList[v].empty() || adjList[v][0] == -1) {
        return;
    }
    for (int neighbor : adjList[v]) {
        if (neighbor != -1) {
            removeEdge(v, neighbor);
            dfs(neighbor);
        }
    }
}
void Graph::fleuryAlgorithm() {
    int startVertex = 0;
    for (int i = 0; i < vertices; ++i) {
        if (adjList[i].size() % 2 != 0) {
            startVertex = i;
            break;
        }
    }
    std::cout << "Eulerian Path/Circuit: ";
    dfs(startVertex);
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
    g.fleuryAlgorithm();
    return 0;
}
