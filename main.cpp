#include <vector>

class Matrix {
public:
    int rows, columns;
    std::vector<std::vector<double>> data;
    Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        data = std::vector<std::vector<double>>(rows, std::vector<double>(columns, 0.0));
    }
};

int main() {
    return 0;
    Matrix m = Matrix(3,3);
}
