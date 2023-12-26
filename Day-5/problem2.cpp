#include <vector>
#include <unordered_map>
#include <utility>  // for pair
#include <iostream>
using namespace std;

class Solution {
public:
    // Approach:
    // The approach involves iterating over all possible submatrices formed by fixing the left and right columns.
    // For each submatrix, we calculate the cumulative sum of columns and apply Kadane's algorithm to find
    // the maximum subarray sum within that column-wise modified array.
    // We maintain the maximum submatrix found so far, and the final result is constructed based on it.

    // Kadane's algorithm to find the subarray with the maximum sum
    pair<int, int> kadane(vector<int>& v) {
        int sum = 0;
        int maxSum = -1e9;
        int start = 0;
        int end = -1;

        int currentStart = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += v[i];

            if (sum > maxSum) {
                maxSum = sum;
                start = currentStart;
                end = i;
            }

            if (sum < 0) {
                sum = 0;
                currentStart = i + 1;
            }
        }

        return {start, end};
    }

    // Function to find the maximum submatrix with a sum of zero
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a) {
        int m = a.size();
        int n = a[0].size();

        int left, right, up, down;
        left = right = up = down = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> arr(m, 0);

            for (int j = i; j < n; ++j) {
                // Update the array by adding the column values
                for (int k = 0; k < m; ++k) {
                    arr[k] += a[k][j];
                }

                // Kadane's algorithm on the modified array to find the maximum subarray
                pair<int, int> subarrayBounds = kadane(arr);
                int subarrayLeft = subarrayBounds.first;
                int subarrayRight = subarrayBounds.second;

                // Update the result if a larger submatrix is found
                if ((j - i + 1) * (subarrayRight - subarrayLeft) > (right - left) * (down - up)) {
                    up = subarrayLeft;
                    down = subarrayRight;
                    left = i;
                    right = j + 1;
                }
            }
        }

        // Construct the result matrix based on the identified submatrix
        vector<vector<int>> result;
        for (int i = up; i < down; ++i) {
            vector<int> row;
            for (int j = left; j < right; ++j) {
                row.push_back(a[i][j]);
            }
            result.push_back(row);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, -1, -4, 1, 2},
        {-1, -1, -1, -2, -3, -4},
        {-2, -3, 4, -1, -2, 1},
        {3, 4, 2, 1, 3, -1}
    };

    // Find the maximum submatrix with a sum of zero
    vector<vector<int>> result = solution.sumZeroMatrix(matrix);

    // Display the result
    cout << "Maximum submatrix with a sum of zero:" << endl;
    for (const auto& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
