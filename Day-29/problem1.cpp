#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Add the namespace directive

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Create a 2D vector for dynamic programming
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Initialize the first row of dp with the values from the matrix
        for (int col = 0; col < cols; col++) {
            dp[0][col] = matrix[0][col];
        }

        // Iterate through the matrix starting from the second row
        for (int row = 1; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Calculate the possible paths from the cell above
                int up = matrix[row][col] + dp[row - 1][col];

                // Calculate the possible paths from the cell diagonally left above
                int leftDiagonal = (col - 1 >= 0) ? matrix[row][col] + dp[row - 1][col - 1] : INT_MAX;

                // Calculate the possible paths from the cell diagonally right above
                int rightDiagonal = (col + 1 < cols) ? matrix[row][col] + dp[row - 1][col + 1] : INT_MAX;

                // Update the current cell with the minimum path
                dp[row][col] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        // Find the minimum falling path sum in the last row
        int minPathSum = *min_element(dp[rows - 1].begin(), dp[rows - 1].end());

        return minPathSum;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the minFallingPathSum function and print the result
    int result = solution.minFallingPathSum(matrix);
    cout << "Minimum Falling Path Sum: " << result << endl;

    return 0;
}

