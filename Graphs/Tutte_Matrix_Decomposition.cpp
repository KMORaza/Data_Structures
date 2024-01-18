#include <iostream>
#include <vector>
#include <Eigen/Dense>
class TutteMatrixDecomposition {
public:
    TutteMatrixDecomposition(int numVertices);
    void addEdge(int v, int w);
    bool findPlanarEmbedding();
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;
    Eigen::MatrixXd computeTutteMatrix();
};
TutteMatrixDecomposition::TutteMatrixDecomposition(int numVertices) : numVertices(numVertices) {
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}
void TutteMatrixDecomposition::addEdge(int v, int w) {
    adjacencyMatrix[v][w] = 1;
    adjacencyMatrix[w][v] = 1;
}
Eigen::MatrixXd TutteMatrixDecomposition::computeTutteMatrix() {
    Eigen::MatrixXd matrix(numVertices - 2, numVertices - 2);
    for (int i = 1; i < numVertices - 1; ++i) {
        for (int j = 1; j < numVertices - 1; ++j) {
            matrix(i - 1, j - 1) = adjacencyMatrix[i][j];
        }
    }
    return matrix;
}
bool TutteMatrixDecomposition::findPlanarEmbedding() {
    Eigen::MatrixXd tutteMatrix = computeTutteMatrix();
    Eigen::VectorXd b = Eigen::VectorXd::Zero(numVertices - 2);
    b(0) = -1;  
    Eigen::VectorXd x = tutteMatrix.fullPivLu().solve(b);
    if (tutteMatrix.determinant() == 0 || x.size() < numVertices - 2) {
        std::cout << "The graph is not planar." << std::endl;
        return false;
    }
    std::cout << "Planar embedding coordinates:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        if (i == 0 || i == numVertices - 1) {
            std::cout << "Vertex " << i << ": (0, 0)" << std::endl;
        } else {
            std::cout << "Vertex " << i << ": (" << x(i - 1) << ", " << x(i - 1) << ")" << std::endl;
        }
    }
    return true;
}
int main() {
    TutteMatrixDecomposition graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.findPlanarEmbedding();
    return 0;
}
