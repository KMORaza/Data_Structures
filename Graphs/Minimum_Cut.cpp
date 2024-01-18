#include <iostream>
#include <vector>
#include <algorithm>
class MinCut {
public:
    MinCut(int numVertices);
    void addEdge(int v, int w, int weight);
    int minCut();
private:
    int numVertices;
    std::vector<std::vector<int>> graph;
    void contract(int u, int v);
};
MinCut::MinCut(int numVertices) : numVertices(numVertices) {
    graph.resize(numVertices, std::vector<int>(numVertices, 0));
}
void MinCut::addEdge(int v, int w, int weight) {
    graph[v][w] += weight;
    graph[w][v] += weight;
}
void MinCut::contract(int u, int v) {
    for (int i = 0; i < numVertices; ++i) {
        graph[u][i] += graph[v][i];
        graph[i][u] += graph[i][v];
    }
    for (int i = 0; i < numVertices; ++i) {
        graph[v][i] = graph[i][v] = 0;
    }
}
int MinCut::minCut() {
    std::vector<int> weight(numVertices, 0);
    std::vector<int> isContracted(numVertices, 0);
    std::vector<int> vertices(numVertices);
    std::iota(vertices.begin(), vertices.end(), 0);
    int minCutValue = std::numeric_limits<int>::max();
    for (int phase = numVertices - 1; phase > 0; --phase) {
        std::vector<int> deg(numVertices, 0);
        for (int i = 0; i < phase; ++i) {
            int u = vertices[i];
            for (int j = i + 1; j < numVertices; ++j) {
                int v = vertices[j];
                deg[u] += graph[u][v];
            }
        }
        int u = 0;
        for (int i = 0; i < phase; ++i) {
            int v = vertices[i];
            isContracted[v] = 0;
            if (i == phase - 1) {
                int cutValue = weight[v] + deg[v];
                if (cutValue < minCutValue) {
                    minCutValue = cutValue;
                }
            }
            weight[v] += deg[v];
            if (weight[v] >= weight[u]) {
                u = v;
            }
        }
        isContracted[u] = 1;
        if (phase > 1) {
            contract(vertices[phase - 1], u);
        }
    }
    return minCutValue;
}
int main() {
    MinCut mc(4);
    mc.addEdge(0, 1, 3);
    mc.addEdge(0, 2, 2);
    mc.addEdge(1, 2, 1);
    mc.addEdge(1, 3, 4);
    mc.addEdge(2, 3, 5);
    int minCutValue = mc.minCut();
    std::cout << "Minimum Cut Value: " << minCutValue << std::endl;
    return 0;
}
