#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the determinant of a matrix using the Laplace expansion method
    // Input: A square matrix represented by a 2D vector 'matrix' of size 'n x n'
    // Output: The determinant of the matrix
    int determinantOfMatrix(vector<vector<int>>& matrix, int n) {
        int det = 0;

        // Base case: If the matrix is 1x1, return the only element
        if (n == 1) {
            return matrix[0][0];
        }

        // Temporary matrix to store cofactors
        vector<vector<int>> tempMat(n, vector<int>(n, 0));

        // Sign multiplier for the Laplace expansion
        int sign = 1;

        // Iterate through each element of the first row
        for (int i = 0; i < n; ++i) {
            // Get the cofactor of matrix[0][i]
            getCofactor(matrix, tempMat, 0, i, n);

            // Recursively find the determinant of the submatrix
            det += sign * matrix[0][i] * determinantOfMatrix(tempMat, n - 1);

            // Change sign for the next iteration (alternating signs for each term)
            sign = -sign;
        }

        return det;
    }

    // Function to get the cofactor of a matrix element
    // Input: Original matrix 'mat', temporary matrix 'tempMat', row 'p', column 'q', and size 'n'
    // Output: Cofactor matrix obtained by excluding the specified row and column
    void getCofactor(vector<vector<int>>& mat, vector<vector<int>>& tempMat, int p, int q, int n) {
        int i = 0, j = 0;

        // Loop to fill the temporary matrix with the cofactor elements
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                // Exclude the specified row and column
                if (row != p && col != q) {
                    tempMat[i][j++] = mat[row][col];

                    // Reset column index when all columns are considered in a row
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }
};

int main() {
    // Example usage of the Solution class and its determinant calculation method
    Solution solution;

    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Calculate and display the determinant using the Solution class method
    int det = solution.determinantOfMatrix(matrix, n);
    cout << "Determinant: " << det << endl;

    return 0;
}
