#include <iostream>
#include <vector>
#include <algorithm>
class Edge {
public:
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
class Graph {
public:
    Graph(int vertices) : numVertices(vertices) {}
    void addEdge(int from, int to, int weight) {
        edges.push_back(Edge(from, to, weight));
    }
    int kruskal() {
        int totalWeight = 0;
        std::sort(edges.begin(), edges.end());
        std::vector<int> parent(numVertices);
        for (int i = 0; i < numVertices; ++i) {
            parent[i] = i;
        }
        for (const Edge& edge : edges) {
            int root1 = findParent(edge.from, parent);
            int root2 = findParent(edge.to, parent);
            if (root1 != root2) {
                totalWeight += edge.weight;
                parent[root1] = root2;
            }
        }
        return totalWeight;
    }
private:
    int numVertices;
    std::vector<Edge> edges;
    int findParent(int vertex, std::vector<int>& parent) {
        if (parent[vertex] != vertex) {
            parent[vertex] = findParent(parent[vertex], parent);
        }
        return parent[vertex];
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
    int minimumSpanningTreeWeight = myGraph.kruskal();
    std::cout << "Weight of the Minimum Spanning Tree: " << minimumSpanningTreeWeight << std::endl;
    return 0;
}
