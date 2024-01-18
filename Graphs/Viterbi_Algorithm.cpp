#include <iostream>
#include <vector>
#include <cmath>
class ViterbiAlgorithm {
public:
    ViterbiAlgorithm(const std::vector<std::vector<double>>& transitionMatrix,
                      const std::vector<std::vector<double>>& emissionMatrix,
                      const std::vector<double>& initialProbabilities)
        : transitionMatrix(transitionMatrix),
          emissionMatrix(emissionMatrix),
          initialProbabilities(initialProbabilities) {}
    std::vector<int> findMostLikelySequence(const std::vector<int>& observations) {
        int numStates = transitionMatrix.size();
        int numObservations = observations.size();
        std::vector<std::vector<double>> viterbi(numStates, std::vector<double>(numObservations, 0.0));
        std::vector<std::vector<int>> backpointer(numStates, std::vector<int>(numObservations, 0));
        for (int i = 0; i < numStates; ++i) {
            viterbi[i][0] = initialProbabilities[i] * emissionMatrix[i][observations[0]];
        }
        for (int t = 1; t < numObservations; ++t) {
            for (int i = 0; i < numStates; ++i) {
                viterbi[i][t] = 0.0;
                backpointer[i][t] = 0;
                for (int j = 0; j < numStates; ++j) {
                    double candidate = viterbi[j][t - 1] * transitionMatrix[j][i] * emissionMatrix[i][observations[t]];
                    if (candidate > viterbi[i][t]) {
                        viterbi[i][t] = candidate;
                        backpointer[i][t] = j;
                    }
                }
            }
        }
        int mostLikelyFinalState = 0;
        for (int i = 1; i < numStates; ++i) {
            if (viterbi[i][numObservations - 1] > viterbi[mostLikelyFinalState][numObservations - 1]) {
                mostLikelyFinalState = i;
            }
        }
        std::vector<int> mostLikelySequence(numObservations);
        mostLikelySequence[numObservations - 1] = mostLikelyFinalState;
        for (int t = numObservations - 2; t >= 0; --t) {
            mostLikelySequence[t] = backpointer[mostLikelySequence[t + 1]][t + 1];
        }
        return mostLikelySequence;
    }
private:
    std::vector<std::vector<double>> transitionMatrix;
    std::vector<std::vector<double>> emissionMatrix;
    std::vector<double> initialProbabilities;
};
int main() {
    std::vector<std::vector<double>> transitionMatrix = {
        {0.7, 0.3},
        {0.4, 0.6}
    };
    std::vector<std::vector<double>> emissionMatrix = {
        {0.1, 0.4, 0.5},
        {0.6, 0.3, 0.1}
    };
    std::vector<double> initialProbabilities = {0.8, 0.2};
    std::vector<int> observations = {0, 1, 2, 0, 2};
    ViterbiAlgorithm viterbi(transitionMatrix, emissionMatrix, initialProbabilities);
    std::vector<int> mostLikelySequence = viterbi.findMostLikelySequence(observations);
    std::cout << "Most likely sequence of hidden states:";
    for (int state : mostLikelySequence) {
        std::cout << " " << state;
    }
    std::cout << std::endl;
    return 0;
}
