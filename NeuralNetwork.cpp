#include "NeuralNetwork.h"
#include <iostream>
#include <cmath> // For exp()

// Activation Function: Sigmoid
// Squashes values between 0 and 1. Essential for non-linearity.
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of Sigmoid Function
// Essential for Backpropagation to calculate gradients.
// If y = sigmoid(x), then f'(x) = y * (1 - y)
double dSigmoid(double x) {
    return x * (1 - x);
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
        values = values.map(sigmoid);
    }

    // 4. Convert output Matrix back to std::vector
    std::vector<double> outputVals;
    for (int i = 0; i < values.getRows(); i++) {
        outputVals.push_back(values.getValueAt(i, 0));
    }
    return outputVals;
}

// Backpropagation Algorithm (Training)
// 1. Performs a forward pass to store layer activations.
// 2. Calculates error (Target - Output).
// 3. Propagates error backwards to update weights and biases using Gradient Descent.
void NeuralNetwork::train(std::vector<double> inputVals, std::vector<double> targetVals) {
    
    // PHASE 1: FORWARD PASS (With State Storage)
    // We need to store the output of each layer to calculate gradients later.
    
    Matrix input(inputVals.size(), 1);
    for(size_t i=0; i<inputVals.size(); i++) input.setValueAt(i, 0, inputVals[i]);

    Matrix target(targetVals.size(), 1);
    for(size_t i=0; i<targetVals.size(); i++) target.setValueAt(i, 0, targetVals[i]);

    std::vector<Matrix> layers;
    layers.push_back(input);

    Matrix values = input;
    for (size_t i = 0; i < weightMatrices.size(); i++) {
        values = weightMatrices[i].multiply(values);
        values = values.add(biasMatrices[i]);
        values = values.map(sigmoid);
        layers.push_back(values);
    }

    Matrix output = layers.back();

    // PHASE 2: BACKWARD PASS (Error Propagation & Weight Update)
    
    // Calculate Output Error: Error = Target - Output
    Matrix error = target.subtract(output);

    // Loop backwards from the last layer to the first
    for (int i = weightMatrices.size() - 1; i >= 0; i--) {
        
        // 1. Calculate Gradients
        // Gradient = LearningRate * Error * dSigmoid(Output)
        Matrix gradients = layers[i + 1].map(dSigmoid);
        gradients = gradients.hadamard(error);
        gradients = gradients.multiply(learningRate);

        // 2. Calculate Deltas
        // Delta = Gradient * Transpose(Previous Layer Output)
        Matrix prevLayerTransposed = layers[i].transpose();
        Matrix deltas = gradients.multiply(prevLayerTransposed);

        // 3. Update Weights and Biases
        weightMatrices[i] = weightMatrices[i].add(deltas);
        biasMatrices[i]   = biasMatrices[i].add(gradients);

        // 4. Propagate Error to Previous Layer
        // Next Error = Transpose(Weights) * Current Error
        if (i > 0) {
            Matrix weightsTransposed = weightMatrices[i].transpose();
            error = weightsTransposed.multiply(error);
        }
    }
}
