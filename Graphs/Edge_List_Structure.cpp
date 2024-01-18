#include <iostream>
#include <vector>
struct Edge {
    int src, dest;
    Edge(int source, int destination) : src(source), dest(destination) {}
};
class EdgeListGraph {
private:
    int numVertices;
    std::vector<Edge> edges;
public:
    EdgeListGraph(int vertices) : numVertices(vertices) {}
    void addEdge(int src, int dest) {
        edges.push_back(Edge(src, dest));
    }
    void printEdges() const {
        std::cout << "Edges of the graph:" << std::endl;
        for (const Edge& edge : edges) {
            std::cout << edge.src << " -> " << edge.dest << std::endl;
        }
    }
};
int main() {
    EdgeListGraph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);
    graph.printEdges();
    return 0;
}
