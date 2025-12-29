#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Matrix.h"
#include <vector>

class NeuralNetwork {
public:
    // Constructor
    // topology: Defines the structure of the network (e.g., {2, 3, 1} means 2 inputs, 3 hidden neurons, 1 output)
    NeuralNetwork(std::vector<int> topology, double learningRate = 0.1);

    // Forward Propagation
    // Takes an input vector and returns the network's prediction
    std::vector<double> feedForward(std::vector<double> inputVals);

    // Backpropagation (Training)
    void train(std::vector<double> inputVals, std::vector<double> targetVals);

private:
    std::vector<int> topology;          // Stores layer sizes
    std::vector<Matrix> weightMatrices; // Stores weights between layers
    std::vector<Matrix> biasMatrices;   // Stores biases for each layer
    double learningRate;                // Speed of learning
};

#endif // NEURALNETWORK_H
