#include <iostream>
#include <vector>
#include <queue>
#include <climits>
class HopcroftKarp {
public:
    HopcroftKarp(int numLeft, int numRight) : numLeft(numLeft), numRight(numRight) {
        leftAdjList.resize(numLeft);
        rightAdjList.resize(numRight);
        matching.assign(numRight, -1);
        dist.assign(numLeft, 0);
    }
    void addEdge(int left, int right) {
        leftAdjList[left].push_back(right);
    }
    int maxMatching() {
        int matchingSize = 0;
        while (bfs()) {
            for (int left = 0; left < numLeft; ++left) {
                if (matching[left] == -1 && dfs(left)) {
                    ++matchingSize;
                }
            }
        }
        return matchingSize;
    }
private:
    int numLeft;
    int numRight;
    std::vector<std::vector<int>> leftAdjList;
    std::vector<std::vector<int>> rightAdjList;
    std::vector<int> matching;
    std::vector<int> dist;
    bool bfs() {
        std::queue<int> q;
        for (int left = 0; left < numLeft; ++left) {
            if (matching[left] == -1) {
                dist[left] = 0;
                q.push(left);
            } else {
                dist[left] = INT_MAX;
            }
        }
        dist[INT_MAX] = INT_MAX;
        while (!q.empty()) {
            int left = q.front();
            q.pop();
            if (dist[left] < dist[INT_MAX]) {
                for (int right : leftAdjList[left]) {
                    if (dist[matching[right]] == INT_MAX) {
                        dist[matching[right]] = dist[left] + 1;
                        q.push(matching[right]);
                    }
                }
            }
        }
        return dist[INT_MAX] != INT_MAX;
    }
    bool dfs(int left) {
        if (left != INT_MAX) {
            for (int right : leftAdjList[left]) {
                if (dist[matching[right]] == dist[left] + 1 && dfs(matching[right])) {
                    matching[right] = left;
                    matching[left] = right;
                    return true;
                }
            }
            dist[left] = INT_MAX;
            return false;
        }
        return true;
    }
};
int main() {
    HopcroftKarp hk(4, 4);
    hk.addEdge(0, 1);
    hk.addEdge(0, 2);
    hk.addEdge(1, 2);
    hk.addEdge(2, 0);
    hk.addEdge(2, 3);
    hk.addEdge(3, 3);
    int maxMatching = hk.maxMatching();
    std::cout << "Maximum Cardinality Matching: " << maxMatching << std::endl;
    return 0;
}
