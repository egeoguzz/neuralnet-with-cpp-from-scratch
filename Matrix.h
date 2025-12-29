#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
private:
    int rows, columns;
    std::vector<std::vector<double>> data;

public:
    // Constructor
    Matrix(int rows, int columns);
    
    // Getters & Setters
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    void setValueAt(int i, int j, double val) { data[i][j] = val; }
    double getValueAt(int i, int j) const { return data[i][j]; }
    
    // Core Operations
    void fillRandom(); // Fills matrix with random values between -1 and 1
    void print();      // Prints matrix to console
    
    // Mathematical Operations
    Matrix transpose();                 // Returns the transpose of the matrix
    Matrix add(const Matrix& B);        // Matrix addition (for Bias)
    Matrix subtract(const Matrix& B);   // Matrix subtraction (for Error calculation)
    Matrix multiply(const Matrix& B);   // Matrix multiplication (Dot Product)
    Matrix multiply(double scalar);     // Scalar multiplication (for Learning Rate)
    Matrix hadamard(const Matrix& B);   // Element-wise multiplication (Hadamard Product)
    
    // Utility
    Matrix map(double (*func)(double)); // Applies a function to every element (for Activation Functions)
};

#endif // MATRIX_H
