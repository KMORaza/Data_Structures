#include <iostream>
#include <vector>
#include <unordered_map>
class Graph {
public:
    Graph() {}
    void addEdge(int u, int v) {
        adjacencyMap[u].push_back(v);
        adjacencyMap[v].push_back(u); 
    }
    void printGraph() {
        for (const auto& pair : adjacencyMap) {
            int vertex = pair.first;
            const std::vector<int>& neighbors = pair.second;
            std::cout << "Vertex " << vertex << " is connected to:";
            for (int neighbor : neighbors) {
                std::cout << " " << neighbor;
            }
            std::cout << std::endl;
        }
    }
private:
    std::unordered_map<int, std::vector<int>> adjacencyMap;
};
int main() {
    Graph myGraph;
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 3);
    myGraph.printGraph();
    return 0;
}
