#include <iostream>
#include <vector>
#include <algorithm>
class MatroidIntersection {
public:
    MatroidIntersection(int numElements);
    void addIndependentSet(int matroid, const std::vector<int>& elements);
    std::vector<int> findIntersection();
private:
    int numElements;
    std::vector<std::vector<int>> independentSets;
    bool isIndependent(const std::vector<int>& set) const;
};
MatroidIntersection::MatroidIntersection(int numElements) : numElements(numElements) {
    independentSets.resize(2); 
}
void MatroidIntersection::addIndependentSet(int matroid, const std::vector<int>& elements) {
    independentSets[matroid] = elements;
}
bool MatroidIntersection::isIndependent(const std::vector<int>& set) const {
    return std::all_of(set.begin(), set.end(), [this](int element) {
        return std::find(independentSets[0].begin(), independentSets[0].end(), element) != independentSets[0].end() &&
               std::find(independentSets[1].begin(), independentSets[1].end(), element) != independentSets[1].end();
    });
}
std::vector<int> MatroidIntersection::findIntersection() {
    std::vector<int> intersection;
    for (int element = 0; element < numElements; ++element) {
        std::vector<int> candidateSet = intersection;
        candidateSet.push_back(element);
        if (isIndependent(candidateSet)) {
            intersection.push_back(element);
        }
    }
    return intersection;
}
int main() {
    MatroidIntersection matroids(5);
    matroids.addIndependentSet(0, {0, 2, 4});
    matroids.addIndependentSet(1, {1, 3});
    std::vector<int> intersection = matroids.findIntersection();
    std::cout << "Intersection of independent sets: ";
    for (int element : intersection) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
