//
// Created by İsmail Ege Oğuz on 20.06.2025.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    int rows, columns;
    std::vector<std::vector<double>> data;
public:
    Matrix(int rows, int columns);
    void fillRandom();
    void print();
    Matrix add(const Matrix& B);
    Matrix multiply(const Matrix& B);
    Matrix transpose();
    Matrix map(double (*func)(double));
};



#endif //MATRIX_H
