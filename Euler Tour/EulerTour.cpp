#include <iostream>
#include <vector>
class EulerTour {
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> eulerTour;
    std::vector<int> inTime;
    std::vector<int> outTime;
    std::vector<bool> visited;
    int time;
    void dfs(int node) {
        visited[node] = true;
        inTime[node] = time++;
        eulerTour.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
                eulerTour.push_back(node); 
            }
        }
        outTime[node] = time++;
    }
public:
    EulerTour(int numNodes) : graph(numNodes), inTime(numNodes), outTime(numNodes), visited(numNodes, false), time(0) {}
    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void performEulerTour(int startNode) {
        dfs(startNode);
    }
    void displayEulerTour() {
        std::cout << "Euler Tour: ";
        for (int node : eulerTour) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
        std::cout << "In Time: ";
        for (int i = 0; i < inTime.size(); ++i) {
            std::cout << inTime[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Out Time: ";
        for (int i = 0; i < outTime.size(); ++i) {
            std::cout << outTime[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    EulerTour eulerTour(7);
    eulerTour.addEdge(0, 1);
    eulerTour.addEdge(0, 2);
    eulerTour.addEdge(1, 3);
    eulerTour.addEdge(1, 4);
    eulerTour.addEdge(2, 5);
    eulerTour.addEdge(2, 6);
    eulerTour.performEulerTour(0);
    eulerTour.displayEulerTour();
    return 0;
}
