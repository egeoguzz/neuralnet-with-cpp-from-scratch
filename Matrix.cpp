#include "Matrix.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <cassert>

// Constructor: Initializes a matrix with zeros
Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    data = std::vector<std::vector<double>>(rows, std::vector<double>(columns, 0.0));
}

// Fills the matrix with random values between -1.0 and 1.0
// Crucial for initializing weights in a Neural Network to avoid saturation
void Matrix::fillRandom() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            data[i][j] = dist(mt);
        }
    }
}

// Prints the matrix to the console with formatting
void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(4) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Matrix Addition
Matrix Matrix::add(const Matrix &B) {
    assert(rows == B.rows && columns == B.columns);
    
    Matrix C(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C.data[i][j] = data[i][j] + B.data[i][j];
        }
    }
    return C;
}

// Matrix Subtraction
Matrix Matrix::subtract(const Matrix &B) {
    assert(rows == B.rows && columns == B.columns);
    
    Matrix C(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C.data[i][j] = data[i][j] - B.data[i][j];
        }
    }
    return C;
}

// Matrix Multiplication (Dot Product)
// This is the core operation for Forward Propagation
Matrix Matrix::multiply(const Matrix &B) {
    assert(columns == B.rows); // Columns of A must match Rows of B
    
    Matrix C(rows, B.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < B.columns; j++) {
            double sum = 0;
            for (int k = 0; k < columns; k++) {
                sum += data[i][k] * B.data[k][j];
            }
            C.data[i][j] = sum;
        }
    }
    return C;
}

// Scalar Multiplication
Matrix Matrix::multiply(double scalar) {
    Matrix C(rows, columns);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            C.data[i][j] = data[i][j] * scalar;
        }
    }
    return C;
}

// Hadamard Product (Element-wise Multiplication)
// Essential for calculating gradients during Backpropagation
Matrix Matrix::hadamard(const Matrix &B) {
    assert(rows == B.rows && columns == B.columns);
    
    Matrix C(rows, columns);
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            C.data[i][j] = data[i][j] * B.data[i][j];
        }
    }
    return C;
}

// Transpose Matrix
// Swaps rows and columns
Matrix Matrix::transpose() {
    Matrix transposed(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed.data[j][i] = data[i][j];
        }
    }
    return transposed;
}

// Applies a function to every element of the matrix
// Used for Activation Functions (e.g., Sigmoid, ReLU)
Matrix Matrix::map(double (*func)(double)) {
    Matrix C(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            C.data[i][j] = func(data[i][j]);
        }
    }
    return C;
}
