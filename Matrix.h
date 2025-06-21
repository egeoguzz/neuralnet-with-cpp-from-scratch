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
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    void setValueAt(int i, int j, double val) { data[i][j] = val; }
    double getValueAt(int i, int j) const { return data[i][j]; }
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        data = std::vector<std::vector<double>>(rows, std::vector<double>(columns));
    };
    void fillRandom();
    void print();
    Matrix add(const Matrix& B);
    Matrix multiply(const Matrix& B);
    Matrix transpose();
    Matrix map(double (*func)(double));
};



#endif //MATRIX_H
