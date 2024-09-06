#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<int> row;
    std::vector<int> col;
    std::vector<int> value;
    int numRows, numCols;

public:
    SparseMatrix(int rows, int cols) : numRows(rows), numCols(cols) {}

    void addElement(int r, int c, int val) {
        if (val != 0) {
            row.push_back(r);
            col.push_back(c);
            value.push_back(val);
        }
    }

    void display() {
        std::cout << "Row\t";
        for (int i : row) std::cout << i << " ";
        std::cout << "\nColumn\t";
        for (int i : col) std::cout << i << " ";
        std::cout << "\nValue\t";
        for (int i : value) std::cout << i << " ";
        std::cout << std::endl;
    }
};

int main() {
    // Define the sparse matrix from the image
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    SparseMatrix sparseMatrix(4, 5);

    // Populate the sparse matrix
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] != 0) {
                sparseMatrix.addElement(i, j, matrix[i][j]);
            }
        }
    }

    // Display the original matrix
    std::cout << "Original Matrix:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Display the sparse matrix representation
    std::cout << "\nSparse Matrix Representation:\n";
    sparseMatrix.display();

    return 0;
}
