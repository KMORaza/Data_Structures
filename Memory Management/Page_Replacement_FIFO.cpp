#include <iostream>
#include <queue>
#include <unordered_set>
class FIFOPageReplacement {
public:
    FIFOPageReplacement(int frameCount) : frameCount(frameCount), pageFaults(0) {}
    void processPageRequests(const std::vector<int>& pageRequests) {
        std::queue<int> pageQueue;
        std::unordered_set<int> pageSet;
        for (int page : pageRequests) {
            if (pageSet.find(page) == pageSet.end()) {
                pageFaults++;
                if (pageQueue.size() == frameCount) {
                    int oldestPage = pageQueue.front();
                    pageQueue.pop();
                    pageSet.erase(oldestPage);
                }
                pageQueue.push(page);
                pageSet.insert(page);
            }
            displayMemoryState(pageQueue);
        }
        std::cout << "Total page faults: " << pageFaults << std::endl;
    }
private:
    void displayMemoryState(const std::queue<int>& pageQueue) const {
        std::cout << "Memory state: ";
        std::queue<int> displayQueue = pageQueue;
        while (!displayQueue.empty()) {
            std::cout << displayQueue.front() << " ";
            displayQueue.pop();
        }
        std::cout << std::endl;
    }
    int frameCount;
    int pageFaults;
};
int main() {
    std::vector<int> pageRequests = {1, 2, 3, 4, 1, 5, 6, 3, 7, 8, 4, 9, 2, 10, 11};
    int frameCount = 3;
    FIFOPageReplacement fifo(frameCount);
    fifo.processPageRequests(pageRequests);
    return 0;
}
