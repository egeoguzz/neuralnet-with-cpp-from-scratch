//
// Created by İsmail Ege Oğuz on 20.06.2025.
//

#include "Matrix.h"
#include <iomanip>
#include <iostream>
#include <random>

Matrix Matrix::add(const Matrix &B) {
    Matrix C = Matrix(B.getRows(), B.getColumns());

    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.columns; j++) {
            C.setValueAt(i,j,this->getValueAt(i,j) + B.getValueAt(i,j));
        }
    }

    return C;
}

void Matrix::print() {
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getColumns(); j++) {
            std::cout << std::setw(6) << std::fixed << std::setprecision(2) << this->getValueAt(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::transpose() {
    Matrix transposed = Matrix(this->getColumns(), this->getRows());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getColumns(); j++) {
            transposed.setValueAt(j,i,this->getValueAt(i,j));
        }
    }
    return transposed;
}

void Matrix::fillRandom() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0);

    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getColumns(); j++) {
            this->setValueAt(i,j,dist(mt));
        }
    }
}


