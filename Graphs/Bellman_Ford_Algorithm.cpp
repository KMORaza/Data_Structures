#include <iostream>
#include <vector>
#include <limits>
const int INF = std::numeric_limits<int>::max();
class Edge {
public:
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {}
    void addEdge(int from, int to, int weight) {
        edges.push_back(Edge(from, to, weight));
    }
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
        for (const Edge& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (distances[u] != INF && distances[u] + w < distances[v]) {
                std::cerr << "Error: Negative weight cycle detected." << std::endl;
                return std::vector<int>();
            }
        }
        return distances;
    }
private:
    int numVertices;
    std::vector<Edge> edges;
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
    int startVertex;
    std::cout << "Enter the starting vertex: ";
    std::cin >> startVertex;
    std::vector<int> shortestDistances = myGraph.bellmanFord(startVertex);
    std::cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "To vertex " << i << ": " << (shortestDistances[i] == INF ? "INF" : std::to_string(shortestDistances[i])) << std::endl;
    }
    return 0;
}
