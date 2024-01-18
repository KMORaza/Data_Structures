#include <iostream>
#include <unordered_set>
#include <queue>
class BidirectionalSearch {
public:
    BidirectionalSearch(int start, int goal) : start(start), goal(goal) {}
    int findMeetingPoint() {
        std::unordered_set<int> visitedStart, visitedGoal;
        std::queue<int> queueStart, queueGoal;
        queueStart.push(start);
        queueGoal.push(goal);
        visitedStart.insert(start);
        visitedGoal.insert(goal);
        while (!queueStart.empty() && !queueGoal.empty()) {
            int meetingPoint;
            if (expandFrontier(queueStart, visitedStart, visitedGoal, meetingPoint)) {
                return meetingPoint;
            }
            if (expandFrontier(queueGoal, visitedGoal, visitedStart, meetingPoint)) {
                return meetingPoint;
            }
        }
        return -1; 
    }
private:
    int start;
    int goal;
    bool expandFrontier(std::queue<int>& queue, std::unordered_set<int>& visited, const std::unordered_set<int>& targetVisited, int& meetingPoint) {
        int current = queue.front();
        queue.pop();
        if (targetVisited.find(current) != targetVisited.end()) {
            meetingPoint = current;
            return true;
        }
        for (int neighbor : getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
        return false;
    }
    std::vector<int> getNeighbors(int current) {
        return {current - 1, current + 1};
    }
};
int main() {
    int start, goal;
    std::cout << "Enter the start and goal values: ";
    std::cin >> start >> goal;
    BidirectionalSearch bidirectionalSearch(start, goal);
    int meetingPoint = bidirectionalSearch.findMeetingPoint();
    if (meetingPoint != -1) {
        std::cout << "Meeting point found at node: " << meetingPoint << std::endl;
    } else {
        std::cout << "No meeting point found!" << std::endl;
    }
    return 0;
}
