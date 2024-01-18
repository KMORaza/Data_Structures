#include <iostream>
#include <vector>
#include <algorithm>
struct Edge {
    int src, dest, weight;
};
class Graph {
public:
    Graph(int vertices, int edges) : numVertices(vertices), numEdges(edges) {}
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }
    void boruvkaMST() {
        std::vector<int> parent(numVertices, -1);
        std::vector<int> cheapest(numVertices, -1);
        std::vector<int> treeRepresentatives;
        while (treeRepresentatives.size() < numVertices - 1) {
            for (const Edge& edge : edges) {
                int set1 = find(parent, edge.src);
                int set2 = find(parent, edge.dest);
                if (set1 != set2) {
                    if (cheapest[set1] == -1 || edge.weight < edges[cheapest[set1]].weight) {
                        cheapest[set1] = edge.weight;
                    }
                    if (cheapest[set2] == -1 || edge.weight < edges[cheapest[set2]].weight) {
                        cheapest[set2] = edge.weight;
                    }
                }
            }
            for (int i = 0; i < numVertices; ++i) {
                if (cheapest[i] != -1) {
                    int set1 = find(parent, edges[cheapest[i]].src);
                    int set2 = find(parent, edges[cheapest[i]].dest);
                    if (set1 != set2) {
                        treeRepresentatives.push_back(cheapest[i]);
                        unionSets(parent, set1, set2);
                    }
                    cheapest[i] = -1;
                }
            }
        }
        printMST(treeRepresentatives);
    }
private:
    int numVertices;
    int numEdges;
    std::vector<Edge> edges;
    int find(std::vector<int>& parent, int vertex) {
        if (parent[vertex] == -1) {
            return vertex;
        }
        return find(parent, parent[vertex]);
    }
    void unionSets(std::vector<int>& parent, int set1, int set2) {
        parent[set1] = set2;
    }
    void printMST(const std::vector<int>& treeRepresentatives) {
        std::cout << "Minimum Spanning Tree (MST):" << std::endl;
        int totalWeight = 0;
        for (int idx : treeRepresentatives) {
            const Edge& edge = edges[idx];
            std::cout << edge.src << " -- " << edge.dest << "   Weight: " << edge.weight << std::endl;
            totalWeight += edge.weight;
        }
        std::cout << "Total Weight of MST: " << totalWeight << std::endl;
    }
};
int main() {
    Graph graph(4, 5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    graph.boruvkaMST();
    return 0;
}
