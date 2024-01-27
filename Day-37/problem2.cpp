#include <iostream>
#include <climits>
#include <string>

using namespace std; // Added for clarity

class Solution {
public:
    string matrixChainOrder(int p[], int n) {
        // Create a 2D table to store minimum multiplications
        int dp[n][n];
        
        // Parenthesis order to store the optimal order
        char order[n][26];  // Fix the size of the array
        
        // Initialize the dp table
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
        }
        
        // Fill the table using bottom-up approach
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k < j; k++) {
                    // Calculate the cost of multiplying matrices and find the minimum
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        order[i][j] = 'A' + k - 1; // Store the optimal split point
                    }
                }
            }
        }
        
        // Reconstruct the optimal order
        string result = "";
        printOrder(order, 1, n - 1, result);
        return result;
    }

private:
    // Recursive function to construct the optimal order
    void printOrder(char order[][26], int i, int j, string &result) {
        if (i == j) {
            // If there is only one matrix, append its label to the result
            result += ('A' + i - 1);
            return;
        }
        
        // Add an opening parenthesis to the result
        result += '(';
        
        // Recursively construct the optimal order for the left and right partitions
        printOrder(order, i, order[i][j] - 'A' + 1, result);
        printOrder(order, order[i][j] - 'A' + 2, j, result);
        
        // Add a closing parenthesis to the result
        result += ')';
    }
};

int main() {
    Solution solution;

    // Example usage with a 4x3x2x5 matrix chain
    int matrixDimensions[] = {4, 3, 2, 5};
    int n = sizeof(matrixDimensions) / sizeof(matrixDimensions[0]);

    string result = solution.matrixChainOrder(matrixDimensions, n);

    cout << "Optimal Matrix Chain Multiplication Order: " << result << endl;

    return 0;
}
