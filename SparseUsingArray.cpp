#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>

// SparseMatrix class: Efficiently represents a matrix with mostly zero elements
class SparseMatrix {
private:
    // Element struct: Represents a non-zero element in the sparse matrix
    struct Element {
        int row, col, value;
        Element(int r, int c, int v) : row(r), col(c), value(v) {}
    };

    std::vector<Element> elements;  // Stores only non-zero elements
    int numRows, numCols;  // Dimensions of the original matrix

public:
    // Constructor: Initializes the matrix dimensions
    SparseMatrix(int rows, int cols) : numRows(rows), numCols(cols) {}

    // addElement: Adds a non-zero element to the sparse matrix
    // Ignores zero values to maintain sparsity
    void addElement(int row, int col, int value) {
        if (value != 0) {
            elements.emplace_back(row, col, value);
        }
    }

    // display: Outputs the sparse matrix in a compact, vertical format
    void display() const {
        // Create a copy for sorting to preserve original order
        std::vector<Element> sortedElements = elements;
        
        // Sort elements for consistent output
        // Uses std::tie for efficient comparison of multiple members
        std::sort(sortedElements.begin(), sortedElements.end(), 
                  [](const Element& a, const Element& b) {
                      return std::tie(a.row, a.col) < std::tie(b.row, b.col);
                  });

        // Output header
        std::cout << "Row\tColumn\tValue\n";
        
        // Output each non-zero element
        for (const auto& elem : sortedElements) {
            std::cout << elem.row << "\t" << elem.col << "\t" << elem.value << "\n";
        }
    }

    // displayOriginal: Reconstructs and displays the original matrix
    void displayOriginal() const {
        // Create a 2D vector to represent the full matrix
        std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));
        
        // Populate the matrix with non-zero elements
        for (const auto& elem : elements) {
            matrix[elem.row][elem.col] = elem.value;
        }
        
        // Output the full matrix
        for (const auto& row : matrix) {
            for (int value : row) {
                // Use setw for aligned output
                std::cout << std::setw(2) << value << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    // Test matrix dimensions
    const int rows = 4, cols = 5;

    // Sample sparse matrix data
    int originalMatrix[rows][cols] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // Create a SparseMatrix object
    SparseMatrix sparseMatrix(rows, cols);

    // displaying the sparse matrix with non-zero elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (originalMatrix[i][j] != 0) {
                sparseMatrix.addElement(i, j, originalMatrix[i][j]);
            }
        }
    }

    // display the original matrix for comparison
    std::cout << "Original Matrix:\n";
    sparseMatrix.displayOriginal();

    // display the sparse representation
    std::cout << "\nSparse Matrix Representation:\n";
    sparseMatrix.display();

    return 0;
}
