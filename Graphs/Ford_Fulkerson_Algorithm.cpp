#include <iostream>
#include <vector>
#include <queue>
#include <climits>
class FordFulkerson {
public:
    FordFulkerson(int vertices) : numVertices(vertices) {
        residualGraph.resize(vertices, std::vector<int>(vertices, 0));
    }
    void addEdge(int from, int to, int capacity) {
        residualGraph[from][to] = capacity;
        residualGraph[to][from] = 0;
    }
    int maxFlow(int source, int sink) {
        int maxFlow = 0;
        while (int pathFlow = findAugmentingPath(source, sink)) {
            maxFlow += pathFlow;
            updateResidualGraph(source, sink, pathFlow);
        }
        return maxFlow;
    }
private:
    int numVertices;
    std::vector<std::vector<int>> residualGraph;
    int findAugmentingPath(int source, int sink) {
        std::vector<int> parent(numVertices, -1);
        std::queue<std::pair<int, int>> q;
        q.push({source, INT_MAX});
        parent[source] = source;
        while (!q.empty()) {
            int u = q.front().first;
            int minCapacity = q.front().second;
            q.pop();
            for (int v = 0; v < numVertices; ++v) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    int newMinCapacity = std::min(minCapacity, residualGraph[u][v]);
                    q.push({v, newMinCapacity});
                    parent[v] = u;
                    if (v == sink) {
                        return newMinCapacity;
                    }
                }
            }
        }
        return 0;
    }
    void updateResidualGraph(int source, int sink, int pathFlow) {
        int v = sink;
        while (v != source) {
            int u = residualGraph[parent[v]][v];
            residualGraph[parent[v]][v] -= pathFlow;
            residualGraph[v][parent[v]] += pathFlow;
            v = parent[v];
        }
    }
};
int main() {
    FordFulkerson ff(6);
    ff.addEdge(0, 1, 10);
    ff.addEdge(0, 2, 5);
    ff.addEdge(1, 2, 15);
    ff.addEdge(1, 3, 10);
    ff.addEdge(2, 3, 10);
    ff.addEdge(2, 4, 10);
    ff.addEdge(3, 4, 5);
    ff.addEdge(4, 5, 10);
    int source = 0;
    int sink = 5;
    int maxFlow = ff.maxFlow(source, sink);
    std::cout << "Maximum Flow from " << source << " to " << sink << ": " << maxFlow << std::endl;
    return 0;
}
