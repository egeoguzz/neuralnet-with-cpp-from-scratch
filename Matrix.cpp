//
// Created by İsmail Ege Oğuz on 20.06.2025.
//

#include "Matrix.h"

Matrix Matrix::add(const Matrix &B) {
    Matrix C = Matrix(B.getRows(), B.getColumns());

    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.columns; j++) {
            C.setValueAt(i,j,this->getValueAt(i,j) + B.getValueAt(i,j));
        }
    }

    return C;
}
