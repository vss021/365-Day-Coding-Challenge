#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Calculate cumulative sums for each row
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int countTarget = 0;

        // Iterate over all possible pairs of columns (c1, c2)
        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = c1; c2 < cols; c2++) {
                unordered_map<int, int> sumCountMap;
                sumCountMap[0] = 1;
                int sum = 0;

                // Iterate over each row and calculate the cumulative sum for the selected columns
                for (int r = 0; r < rows; r++) {
                    sum += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                    countTarget += sumCountMap[sum - target];
                    sumCountMap[sum]++;
                }
            }
        }

        return countTarget;
    }
};


int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example matrix (you can replace this with your actual input matrix)
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int target = 2;

    // Call the numSubmatrixSumTarget function
    int result = solution.numSubmatrixSumTarget(matrix, target);

    // Display the result
    cout << "Number of submatrices with sum equal to target: " << result << endl;

    return 0;
}
