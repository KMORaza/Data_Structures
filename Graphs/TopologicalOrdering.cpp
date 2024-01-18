#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
class Graph {
public:
    Graph() {}
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
        adjacencyList[from].push_back(to);
    }
    std::vector<int> topologicalSort() {
        std::vector<int> result;
        std::unordered_set<int> visited;
        std::stack<int> stack;
        for (const auto& entry : adjacencyList) {
            int vertex = entry.first;
            if (visited.find(vertex) == visited.end()) {
                topologicalSortUtil(vertex, visited, stack);
            }
        }
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        return result;
    }
private:
    std::unordered_map<int, std::vector<int>> adjacencyList;
    void topologicalSortUtil(int vertex, std::unordered_set<int>& visited, std::stack<int>& stack) {
        visited.insert(vertex);
        for (int neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }
        stack.push(vertex);
    }
};
int main() {
    Graph myGraph;
    myGraph.addVertex(0);
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    std::cout << "Topological Ordering of the Graph: ";
    std::vector<int> ordering = myGraph.topologicalSort();
    for (int vertex : ordering) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    return 0;
}
