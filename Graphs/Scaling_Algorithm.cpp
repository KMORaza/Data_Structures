#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
class GabowSCC {
public:
    GabowSCC(int vertices);
    void addEdge(int v, int w);
    std::vector<std::vector<int>> findSCCs();
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    std::vector<int> discoveryTime;
    std::vector<int> lowLink;
    std::vector<bool> inStack;
    std::stack<int> dfsStack;
    int currentTime;
    void dfs(int vertex);
    void strongConnect(int v);
};
GabowSCC::GabowSCC(int vertices) : vertices(vertices), currentTime(0) {
    adjList.resize(vertices);
    discoveryTime.resize(vertices, -1);
    lowLink.resize(vertices, -1);
    inStack.resize(vertices, false);
}
void GabowSCC::addEdge(int v, int w) {
    adjList[v].push_back(w);
}
void GabowSCC::dfs(int vertex) {
    discoveryTime[vertex] = currentTime;
    lowLink[vertex] = currentTime;
    currentTime++;
    dfsStack.push(vertex);
    inStack[vertex] = true;
    for (int neighbor : adjList[vertex]) {
        if (discoveryTime[neighbor] == -1) {
            dfs(neighbor);
            lowLink[vertex] = std::min(lowLink[vertex], lowLink[neighbor]);
        } else if (inStack[neighbor]) {
            lowLink[vertex] = std::min(lowLink[vertex], discoveryTime[neighbor]);
        }
    }
    if (lowLink[vertex] == discoveryTime[vertex]) {
        strongConnect(vertex);
    }
}
void GabowSCC::strongConnect(int v) {
    std::vector<int> scc;
    int w;
    do {
        w = dfsStack.top();
        dfsStack.pop();
        inStack[w] = false;
        scc.push_back(w);
    } while (w != v);
    std::cout << "Strongly Connected Component:";
    for (int node : scc) {
        std::cout << " " << node;
    }
    std::cout << std::endl;
}
std::vector<std::vector<int>> GabowSCC::findSCCs() {
    for (int i = 0; i < vertices; ++i) {
        if (discoveryTime[i] == -1) {
            dfs(i);
        }
    }
    discoveryTime.assign(vertices, -1);
    lowLink.assign(vertices, -1);
    inStack.assign(vertices, false);
    currentTime = 0;
    std::vector<std::vector<int>> sccList;
    while (!dfsStack.empty()) {
        int vertex = dfsStack.top();
        dfsStack.pop();
        if (discoveryTime[vertex] == -1) {
            strongConnect(vertex);
        }
    }
    return sccList;
}
int main() {
    GabowSCC g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 7);
    std::vector<std::vector<int>> sccList = g.findSCCs();
    return 0;
}
