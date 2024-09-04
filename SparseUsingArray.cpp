#include <iostream>
#include <vector>

struct Element {
    int row, col, value;
    Element(int r, int c, int v) : row(r), col(c), value(v) {}
};

class SparseMatrix {
private:
    std::vector<Element> elements;
    int numRows, numCols;

public:
    SparseMatrix(int r, int c) : numRows(r), numCols(c) {}

    void insert(int r, int c, int v) {
        if (v != 0) {
            elements.emplace_back(r, c, v);
        }
    }

    void display() {
        std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));
        for (const auto& elem : elements) {
            matrix[elem.row][elem.col] = elem.value;
        }
        for (const auto& row : matrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);
    sm.insert(0, 2, 3);
    sm.insert(0, 4, 4);
    sm.insert(1, 2, 5);
    sm.insert(1, 3, 7);
    sm.insert(3, 1, 2);
    sm.insert(3, 2, 6);
    sm.display();
    return 0;
}
