#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
struct Node {
    int x, y; 
    int g;     
    int h;   
    int f;  
    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h) {}
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};
class AStar {
public:
    AStar(std::vector<std::vector<int>>& grid, std::pair<int, int> start, std::pair<int, int> goal)
        : grid(grid), start(start), goal(goal) {}
    std::vector<std::pair<int, int>> findPath() {
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
        std::unordered_map<std::pair<int, int>, std::pair<int, int>> cameFrom;
        std::unordered_map<std::pair<int, int>, int> gScore;
        openSet.push(Node(start.first, start.second, 0, heuristic(start, goal)));
        gScore[start] = 0;
        while (!openSet.empty()) {
            Node current = openSet.top();
            openSet.pop();
            if (std::make_pair(current.x, current.y) == goal) {
                return reconstructPath(cameFrom, current);
            }
            for (const auto& neighbor : getNeighbors(current)) {
                int tentativeGScore = gScore[{current.x, current.y}] + 1;
                if (tentativeGScore < gScore[neighbor]) {
                    cameFrom[neighbor] = {current.x, current.y};
                    gScore[neighbor] = tentativeGScore;
                    int h = heuristic(neighbor, goal);
                    openSet.push(Node(neighbor.first, neighbor.second, tentativeGScore, h));
                }
            }
        }
        return {};
    }
private:
    std::vector<std::vector<int>> grid;
    std::pair<int, int> start;
    std::pair<int, int> goal;
    int heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return static_cast<int>(std::hypot(a.first - b.first, a.second - b.second));
    }
    std::vector<std::pair<int, int>> getNeighbors(const Node& node) {
        std::vector<std::pair<int, int>> neighbors;
        int rows = grid.size();
        int cols = grid[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int newX = node.x + dx[i];
            int newY = node.y + dy[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] != 0) {
                neighbors.emplace_back(newX, newY);
            }
        }
        return neighbors;
    }
    std::vector<std::pair<int, int>> reconstructPath(const std::unordered_map<std::pair<int, int>, std::pair<int, int>>& cameFrom, const Node& current) {
        std::vector<std::pair<int, int>> path;
        std::pair<int, int> currentPos = {current.x, current.y};
        while (cameFrom.find(currentPos) != cameFrom.end()) {
            path.push_back(currentPos);
            currentPos = cameFrom.at(currentPos);
        }
        path.push_back(start);
        std::reverse(path.begin(), path.end());
        return path;
    }
};
int main() {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };
    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {3, 4};
    AStar astar(grid, start, goal);
    std::vector<std::pair<int, int>> path = astar.findPath();
    if (path.empty()) {
        std::cout << "No path found!" << std::endl;
    } else {
        std::cout << "Path found:" << std::endl;
        for (const auto& point : path) {
            std::cout << "(" << point.first << ", " << point.second << ") ";
        }
        std::cout << std::endl;
    }
    return 0;
}
