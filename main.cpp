#include <iostream>
#include <vector>
#include "NeuralNetwork.h"

int main() {
    // Define a simple network: 2 Inputs -> 3 Hidden Neurons -> 1 Output Neuron
    std::vector<int> topology = {2, 3, 1};
    NeuralNetwork nn(topology);

    // Dummy Input
    std::vector<double> input = {1.0, 0.0};
    
    std::cout << "Feed Forward Test..." << std::endl;
    std::vector<double> output = nn.feedForward(input);

    std::cout << "Input: 1.0, 0.0" << std::endl;
    // Should print a random value between 0 and 1
    std::cout << "Output: " << output[0] << std::endl;

    return 0;
}
