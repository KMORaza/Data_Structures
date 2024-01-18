#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
class PlanarityTesting {
public:
    PlanarityTesting(int numVertices);
    void addEdge(int v, int w);
    bool isPlanar();
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;
    bool isKuratowskiSubgraph();
    bool hasKuratowskiSubgraph(int u, int v, std::vector<int>& parent, std::vector<int>& dfsNum, std::vector<int>& dfsLow);
};
PlanarityTesting::PlanarityTesting(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}
void PlanarityTesting::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);
}
bool PlanarityTesting::isKuratowskiSubgraph() {
    std::vector<int> parent(numVertices, -1);
    std::vector<int> dfsNum(numVertices, -1);
    std::vector<int> dfsLow(numVertices, -1);
    return hasKuratowskiSubgraph(0, 0, parent, dfsNum, dfsLow);
}
bool PlanarityTesting::hasKuratowskiSubgraph(int u, int v, std::vector<int>& parent, std::vector<int>& dfsNum, std::vector<int>& dfsLow) {
    static int dfsCount = 0;
    dfsNum[u] = dfsLow[u] = dfsCount++;
    for (int neighbor : adjacencyList[u]) {
        if (dfsNum[neighbor] == -1) {
            parent[neighbor] = u;
            if (hasKuratowskiSubgraph(neighbor, u, parent, dfsNum, dfsLow)) {
                return true;
            }
            dfsLow[u] = std::min(dfsLow[u], dfsLow[neighbor]);
            if (dfsLow[neighbor] > dfsNum[u]) {
                return true;  
            }
        } else if (neighbor != v && dfsNum[neighbor] < dfsNum[u]) {
            dfsLow[u] = std::min(dfsLow[u], dfsNum[neighbor]);
        }
    }
    return false;
}
bool PlanarityTesting::isPlanar() {
    if (numVertices < 4) {
        return true;  
    }
    if (isKuratowskiSubgraph()) {
        std::cout << "The graph is not planar." << std::endl;
        return false;
    }
    std::cout << "The graph is planar." << std::endl;
    return true;
}
int main() {
    PlanarityTesting graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.isPlanar();
    return 0;
}
