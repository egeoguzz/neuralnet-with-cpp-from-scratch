#include <vector>
#include "Matrix.h"
#include <iostream>

int main() {
    Matrix m = Matrix(3,3);
    Matrix m2 = Matrix(3,3);
    m2.setValueAt(0,0, 1);
    m.setValueAt(0,0, 1);
    Matrix c = m.add(m2);
    std::cout << c.getValueAt(0,0);
    return 0;
}
