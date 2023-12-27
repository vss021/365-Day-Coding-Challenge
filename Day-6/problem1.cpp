#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    // Function to extract the anti-diagonal pattern from a given matrix
    // The anti-diagonal pattern is obtained by traversing the diagonals from the top-right to bottom-left
    // The matrix is divided into two parts: the upper part and the lower part

    // Upper part of the matrix
    // Start from the first column (i=0) and traverse each diagonal from top to bottom
    // The diagonal is traversed from the top to the bottom by incrementing the row and decrementing the column
    vector<int> antiDiagonalPatternUpper(const vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            int row = 0;
            int col = i;
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }

        return result;
    }

    // Lower part of the matrix
    // Start from the last row (i=1) and traverse each diagonal from top to bottom
    // The diagonal is traversed from the top to the bottom by incrementing the row and decrementing the column
    vector<int> antiDiagonalPatternLower(const vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();

        for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }

        return result;
    }

    // Main function to get the anti-diagonal pattern by combining upper and lower parts
    vector<int> antiDiagonalPattern(const vector<vector<int>>& matrix) {
        vector<int> result;

        // Combine upper and lower parts of the anti-diagonal pattern
        auto upperPart = antiDiagonalPatternUpper(matrix);
        auto lowerPart = antiDiagonalPatternLower(matrix);

        result.insert(result.end(), upperPart.begin(), upperPart.end());
        result.insert(result.end(), lowerPart.begin(), lowerPart.end());

        return result;
    }
};


int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Get the anti-diagonal pattern from the matrix
    vector<int> result = solution.antiDiagonalPattern(matrix);

    // Display the result
    cout << "Anti-Diagonal Pattern: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
