#include <iostream>
#include <vector>
#include "NeuralNetwork.h"

int main() {
    // 1. Architecture Setup
    // 2 Input Neurons, 3 Hidden Neurons, 1 Output Neuron
    std::vector<int> topology = {2, 3, 1};
    NeuralNetwork nn(topology, 0.1); // Learning Rate = 0.1

    // 2. Training Data (XOR Problem)
    // Inputs: {0,0}, {0,1}, {1,0}, {1,1}
    // Targets: {0},   {1},   {1},   {0}
    std::vector<std::vector<double>> trainingInputs = {
        {0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}, {1.0, 1.0}
    };
    std::vector<std::vector<double>> trainingOutputs = {
        {0.0}, {1.0}, {1.0}, {0.0}
    };

    std::cout << "Training the Neural Network (5000 Epochs)..." << std::endl;

    // 3. Training Loop
    for (int epoch = 0; epoch < 5000; epoch++) {
        for (int i = 0; i < trainingInputs.size(); i++) {
            nn.train(trainingInputs[i], trainingOutputs[i]);
        }
    }
    
    std::cout << "Training Complete.\n" << std::endl;

    // 4. Testing
    std::cout << "--- XOR Prediction Results ---" << std::endl;
    for (int i = 0; i < trainingInputs.size(); i++) {
        std::vector<double> output = nn.feedForward(trainingInputs[i]);
        std::cout << "Input: " << trainingInputs[i][0] << ", " << trainingInputs[i][1]
                  << " | Expected: " << trainingOutputs[i][0]
                  << " | Prediction: " << output[0] << std::endl;
    }

    return 0;
}
