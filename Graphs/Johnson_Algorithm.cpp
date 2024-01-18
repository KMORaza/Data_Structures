#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
const int INF = std::numeric_limits<int>::max() / 2;
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {}
    void addEdge(int from, int to, int weight) {
        edges.push_back({from, to, weight});
    }
    std::vector<std::vector<int>> johnson() {
        for (int i = 0; i < numVertices; ++i) {
            addEdge(numVertices, i, 0);
        }
        std::vector<int> potentialDistances = bellmanFord(numVertices);
        for (Edge& edge : edges) {
            edge.weight += potentialDistances[edge.from] - potentialDistances[edge.to];
        }
        std::vector<std::vector<int>> shortestPaths(numVertices, std::vector<int>(numVertices, INF));
        for (int i = 0; i < numVertices; ++i) {
            std::vector<int> distances = dijkstra(i);
            shortestPaths[i] = distances;
        }
        return shortestPaths;
    }
private:
    int numVertices;
    std::vector<Edge> edges;
    class Edge {
    public:
        int from, to, weight;
        Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    };
    std::vector<int> bellmanFord(int startVertex) {
        std::vector<int> distances(numVertices, INF);
        distances[startVertex] = 0;
        for (int i = 0; i < numVertices - 1; ++i) {
            for (const Edge& edge : edges) {
                int u = edge.from;
                int v = edge.to;
                int w = edge.weight;
                if (distances[u] != INF && distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }
        return distances;
    }
    std::vector<int> dijkstra(int startVertex) {
        std::vector<int> distances(numVertices, INF);
        distances[startVertex] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        minHeap.push({0, startVertex});
        while (!minHeap.empty()) {
            int currentDistance = minHeap.top().first;
            int currentVertex = minHeap.top().second;
            minHeap.pop();
            if (currentDistance > distances[currentVertex]) {
                continue;
            }
            for (const Edge& edge : edges) {
                if (edge.from == currentVertex) {
                    int neighborVertex = edge.to;
                    int edgeWeight = edge.weight;
                    int newDistance = distances[currentVertex] + edgeWeight;
                    if (newDistance < distances[neighborVertex]) {
                        distances[neighborVertex] = newDistance;
                        minHeap.push({newDistance, neighborVertex});
                    }
                }
            }
        }
        return distances;
    }
};
int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> numVertices >> numEdges;
    Graph myGraph(numVertices);
    std::cout << "Enter the edges (from to weight):" << std::endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        myGraph.addEdge(from, to, weight);
    }
    std::vector<std::vector<int>> allPairsShortestPaths = myGraph.johnson();
    std::cout << "All-Pairs Shortest Paths:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << (allPairsShortestPaths[i][j] == INF ? "INF" : std::to_string(allPairsShortestPaths[i][j])) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
