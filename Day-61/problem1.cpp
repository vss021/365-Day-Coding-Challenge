#include <iostream>
#include <string>
#include <cstring> // for memset
using namespace std;

class Solution {
public:
    // Define a 3D array for dynamic programming
    int dp[201][201][2];

    // Recursive function to solve the problem
    int solve(string &s, int start, int end, int isTrue) {
        // Base case: if start index exceeds end index, return 0
        if (start > end) return 0;
        
        // Base case: if start index is equal to end index
        if (start == end) {
            if (isTrue) return s[start] == 'T';
            else return s[start] == 'F';
        }
        
        // If the result for this subproblem is already calculated, return it
        if (dp[start][end][isTrue] != -1) return dp[start][end][isTrue];
        
        int ways = 0;
        // Iterate over all possible operators (&, |, ^) in the string
        for (int k = start + 1; k <= end - 1; k += 2) {
            int leftTrue = solve(s, start, k - 1, 1);
            int leftFalse = solve(s, start, k - 1, 0);
            int rightTrue = solve(s, k + 1, end, 1);
            int rightFalse = solve(s, k + 1, end, 0);

            // Depending on the operator, calculate the number of ways
            if (s[k] == '&') {
                if (isTrue) ways += (leftTrue * rightTrue);
                else ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
            } else if (s[k] == '|') {
                if (isTrue) ways += (leftTrue * rightTrue) + (leftFalse * rightTrue) + (leftTrue * rightFalse);
                else ways += (leftFalse * rightFalse);
            } else if (s[k] == '^') {
                if (isTrue) ways += (leftFalse * rightTrue) + (leftTrue * rightFalse);
                else ways += (leftFalse * rightFalse) + (leftTrue * rightTrue);
            }
        }
        
        // Store the result in the dp array and return
        return dp[start][end][isTrue] = (ways % 1003);
    }

    // Function to count the number of ways to parenthesize the expression
    int countWays(int N, string S) {
        // Initialize the dp array with -1
        memset(dp, -1, sizeof(dp));
        // Call the solve function recursively
        return solve(S, 0, N - 1, 1);
    }
};

int main() {
    Solution sol;
    string expression = "T|T&F^T";
    int ways = sol.countWays(expression.size(), expression);
    cout << "Number of ways to parenthesize the expression: " << ways << endl;
    return 0;
}
