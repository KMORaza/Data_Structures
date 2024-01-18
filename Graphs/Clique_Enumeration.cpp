#include <iostream>
#include <vector>
#include <set>
class CliqueEnumerationAlgorithm {
public:
    CliqueEnumerationAlgorithm(int numVertices);
    void addEdge(int v, int w);
    void enumerateCliques();
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
    void bronKerbosch(std::set<int>& R, std::set<int>& P, std::set<int>& X);
};
CliqueEnumerationAlgorithm::CliqueEnumerationAlgorithm(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}
void CliqueEnumerationAlgorithm::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);
}
void CliqueEnumerationAlgorithm::bronKerbosch(std::set<int>& R, std::set<int>& P, std::set<int>& X) {
    if (P.empty() && X.empty()) {
        std::cout << "Clique: ";
        for (int vertex : R) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (auto vertex : P) {
        std::set<int> newR = R;
        newR.insert(vertex);
        bronKerbosch(newR, P.intersection(adjacencyList[vertex]), X.intersection(adjacencyList[vertex]));
        P.erase(vertex);
        X.insert(vertex);
    }
}
void CliqueEnumerationAlgorithm::enumerateCliques() {
    std::set<int> R, P, X;
    for (int i = 0; i < numVertices; ++i) {
        P.insert(i);
    }
    bronKerbosch(R, P, X);
}
int main() {
    CliqueEnumerationAlgorithm graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.enumerateCliques();
    return 0;
}
