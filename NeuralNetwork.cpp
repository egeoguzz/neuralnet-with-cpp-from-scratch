#include "NeuralNetwork.h"
#include <iostream>
#include <cmath> // For exp()

// Activation Function: Sigmoid
// Squashes values between 0 and 1. Essential for non-linearity.
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Constructor: Initializes the network architecture
NeuralNetwork::NeuralNetwork(std::vector<int> topology, double learningRate) {
    this->topology = topology;
    this->learningRate = learningRate;

    // Initialize matrices for weights and biases
    // We iterate from 0 to size-1 because weights exist BETWEEN layers
    for (size_t i = 0; i < topology.size() - 1; i++) {
        
        // Weight Matrix: Rows = Next Layer Neurons, Cols = Current Layer Neurons
        Matrix weightMatrix(topology[i + 1], topology[i]);
        weightMatrix.fillRandom(); // Initialize with random small values
        weightMatrices.push_back(weightMatrix);

        // Bias Matrix: Rows = Next Layer Neurons, Cols = 1
        Matrix biasMatrix(topology[i + 1], 1);
        biasMatrix.fillRandom(); // Initialize with random small values
        biasMatrices.push_back(biasMatrix);
    }
}

// Forward Propagation: Calculates the output based on inputs
std::vector<double> NeuralNetwork::feedForward(std::vector<double> inputVals) {
    // 1. Validation: Check if input size matches the input layer size
    if(inputVals.size() != topology[0]) {
        std::cerr << "ERROR: Input size does not match network topology!" << std::endl;
        exit(1);
    }

    // 2. Convert input std::vector to Matrix (Column Vector)
    Matrix values(inputVals.size(), 1);
    for (size_t i = 0; i < inputVals.size(); i++) {
        values.setValueAt(i, 0, inputVals[i]);
    }

    // 3. Propagate through the layers
    for (size_t i = 0; i < weightMatrices.size(); i++) {
        // a) Linear Transformation: Z = Weights * Input + Bias
        values = weightMatrices[i].multiply(values);
        values = values.add(biasMatrices[i]);
        
        // b) Activation: A = Sigmoid(Z)
        values = values.map(sigmoid);
    }

    // 4. Convert output Matrix back to std::vector
    std::vector<double> outputVals;
    for (int i = 0; i < values.getRows(); i++) {
        outputVals.push_back(values.getValueAt(i, 0));
    }
    return outputVals;
}

// Training function (Placeholder for Step 3)
void NeuralNetwork::train(std::vector<double> inputVals, std::vector<double> targetVals) {
    std::cout << "Training function is not implemented yet." << std::endl;
}
