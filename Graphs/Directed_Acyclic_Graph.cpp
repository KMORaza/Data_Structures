#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
class DAG {
public:
    DAG() {}
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = std::vector<int>();
        }
    }
    void addEdge(int from, int to) {
        if (adjacencyList.find(from) == adjacencyList.end() || adjacencyList.find(to) == adjacencyList.end()) {
            std::cerr << "Error: Vertices not found in the graph." << std::endl;
            return;
        }
        if (hasCycle(from, to)) {
            std::cerr << "Error: Adding the edge creates a cycle in the graph." << std::endl;
            return;
        }
        adjacencyList[from].push_back(to);
    }
    void topologicalSort() {
        std::vector<int> inDegree(getNumVertices(), 0);
        for (const auto& entry : adjacencyList) {
            for (int neighbor : entry.second) {
                inDegree[neighbor]++;
            }
        }
        std::queue<int> zeroInDegreeVertices;
        for (int i = 0; i < getNumVertices(); ++i) {
            if (inDegree[i] == 0) {
                zeroInDegreeVertices.push(i);
            }
        }
        while (!zeroInDegreeVertices.empty()) {
            int currentVertex = zeroInDegreeVertices.front();
            zeroInDegreeVertices.pop();
            std::cout << currentVertex << " ";
            for (int neighbor : adjacencyList[currentVertex]) {
                if (--inDegree[neighbor] == 0) {
                    zeroInDegreeVertices.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }
private:
    std::unordered_map<int, std::vector<int>> adjacencyList;
    bool hasCycleUtil(int vertex, std::unordered_set<int>& visited, std::unordered_set<int>& recursionStack) {
        visited.insert(vertex);
        recursionStack.insert(vertex);
        for (int neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                if (hasCycleUtil(neighbor, visited, recursionStack)) {
                    return true;
                }
            } else if (recursionStack.find(neighbor) != recursionStack.end()) {
                return true;
            }
        }
        recursionStack.erase(vertex);
        return false;
    }
    bool hasCycle(int from, int to) {
        DAG tempGraph = *this;
        tempGraph.addEdge(from, to);
        std::unordered_set<int> visited;
        std::unordered_set<int> recursionStack;
        for (const auto& entry : tempGraph.adjacencyList) {
            int vertex = entry.first;
            if (visited.find(vertex) == visited.end()) {
                if (hasCycleUtil(vertex, visited, recursionStack)) {
                    return true;
                }
            }
        }
        return false;
    }
    int getNumVertices() const {
        return static_cast<int>(adjacencyList.size());
    }
};
int main() {
    DAG myDAG;
    myDAG.addVertex(0);
    myDAG.addVertex(1);
    myDAG.addVertex(2);
    myDAG.addVertex(3);
    myDAG.addEdge(0, 1);
    myDAG.addEdge(0, 2);
    myDAG.addEdge(1, 2);
    myDAG.addEdge(2, 3);
    std::cout << "Topological Sorting of the DAG: ";
    myDAG.topologicalSort();
    return 0;
}
