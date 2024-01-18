#include <iostream>
#include <vector>
#include <queue>
#include <climits>
class EdmondsKarp {
public:
    EdmondsKarp(int vertices) : numVertices(vertices) {
        residualGraph.resize(vertices, std::vector<int>(vertices, 0));
    }
    void addEdge(int from, int to, int capacity) {
        residualGraph[from][to] = capacity;
        residualGraph[to][from] = 0;
    }
    int maxFlow(int source, int sink) {
        int maxFlow = 0;
        std::vector<std::vector<int>> parent(numVertices);
        while (bfs(source, sink, parent)) {
            int pathFlow = INT_MAX;
            for (int v = sink; v != source; v = parent[v][0]) {
                int u = parent[v][0];
                pathFlow = std::min(pathFlow, residualGraph[u][v]);
            }
            for (int v = sink; v != source; v = parent[v][0]) {
                int u = parent[v][0];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }
private:
    int numVertices;
    std::vector<std::vector<int>> residualGraph;
    bool bfs(int source, int sink, std::vector<std::vector<int>>& parent) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source].push_back(-1); 
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < numVertices; ++v) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    q.push(v);
                    parent[v].push_back(u);
                    visited[v] = true;
                    if (v == sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main() {
    EdmondsKarp ek(6);
    ek.addEdge(0, 1, 10);
    ek.addEdge(0, 2, 5);
    ek.addEdge(1, 2, 15);
    ek.addEdge(1, 3, 10);
    ek.addEdge(2, 3, 10);
    ek.addEdge(2, 4, 10);
    ek.addEdge(3, 4, 5);
    ek.addEdge(4, 5, 10);
    int source = 0;
    int sink = 5;
    int maxFlow = ek.maxFlow(source, sink);
    std::cout << "Maximum Flow from " << source << " to " << sink << ": " << maxFlow << std::endl;
    return 0;
}
