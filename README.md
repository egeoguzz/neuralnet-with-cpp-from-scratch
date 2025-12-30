# Neural Network Implementation in C++

A standard C++11 implementation of a Multi-Layer Perceptron (MLP) Neural Network. This project demonstrates the fundamental mathematical concepts behind deep learning by implementing matrix operations, forward propagation, and backpropagation algorithms from scratch, without reliance on external frameworks like TensorFlow or PyTorch.

![Language](https://img.shields.io/badge/language-C++-blue.svg)
![License](https://img.shields.io/badge/license-MIT-grey.svg)

## Technical Overview

The objective of this project is to provide a clear, low-level understanding of neural network mechanics. It handles memory management and linear algebra operations manually using the C++ Standard Library.

### Key Implementation Details
* **Zero Dependencies:** Built strictly with `<vector>`, `<cmath>`, and `<random>`.
* **Linear Algebra Module:** Custom `Matrix` class implementing dot products, transposition, and Hadamard products required for vectorization.
* **Backpropagation Engine:** Implements Gradient Descent using the Chain Rule to minimize the loss function.
* **Dynamic Architecture:** Supports variable network topologies (e.g., input size, hidden layer count/size, output size).

## Mathematical Foundation

The implementation follows standard neural network equations:

1.  **Linear Transformation:**
    $$Z^{[l]} = W^{[l]} \cdot A^{[l-1]} + b^{[l]}$$
2.  **Sigmoid Activation:**
    $$A^{[l]} = \sigma(Z^{[l]}) = \frac{1}{1 + e^{-Z^{[l]}}}$$
3.  **Weight Update (Gradient Descent):**
    $$W^{[l]} = W^{[l]} - \alpha \frac{\partial \mathcal{L}}{\partial W^{[l]}}$$

## Build and Execution

### Prerequisites
* G++ Compiler (C++11 or higher)
* Make (Optional, direct compilation commands provided below)

### Compilation
To compile the source code:

```bash
g++ main.cpp Matrix.cpp NeuralNetwork.cpp -o neuralnet
