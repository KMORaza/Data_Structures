#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>
const int INF = std::numeric_limits<int>::max();
class Graph {
public:
    Graph() {}
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = std::vector<std::pair<int, int>>();
        }
    }
    void addEdge(int from, int to, int weight) {
        adjacencyList[from].emplace_back(to, weight);
    }
    std::vector<int> dijkstra(int startVertex) {
        std::vector<int> distances(adjacencyList.size(), INF);
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
            for (const auto& neighbor : adjacencyList[currentVertex]) {
                int neighborVertex = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDistance = distances[currentVertex] + edgeWeight;
                if (newDistance < distances[neighborVertex]) {
                    distances[neighborVertex] = newDistance;
                    minHeap.push({newDistance, neighborVertex});
                }
            }
        }
        return distances;
    }
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjacencyList;
};
int main() {
    Graph myGraph;
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> numVertices >> numEdges;
    for (int i = 0; i < numVertices; ++i) {
        myGraph.addVertex(i);
    }
    std::cout << "Enter the edges (from to weight):" << std::endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        myGraph.addEdge(from, to, weight);
    }
    int startVertex;
    std::cout << "Enter the starting vertex: ";
    std::cin >> startVertex;
    std::vector<int> shortestDistances = myGraph.dijkstra(startVertex);
    std::cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "To vertex " << i << ": " << (shortestDistances[i] == INF ? "INF" : std::to_string(shortestDistances[i])) << std::endl;
    }
    return 0;
}
