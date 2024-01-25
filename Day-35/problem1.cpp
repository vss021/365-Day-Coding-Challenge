#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    // Function to find the length of the Longest Common Subsequence
    int longestCommonSubsequence(string &a, string &b, int n, int m) {
        // Base case: if either of the strings is empty, the LCS length is 0
        if (n == 0 || m == 0) {
            return 0;
        }

        // Check if the result is already computed for this pair of lengths
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        // If the last characters of both strings are equal
        if (a[n - 1] == b[m - 1]) {
            // Include the common character and move to the next characters in both strings
            return dp[n][m] = 1 + longestCommonSubsequence(a, b, n - 1, m - 1);
        }

        // If the last characters are different, consider two cases:
        // 1. Exclude the last character of string 'a' and find LCS of the remaining strings
        // 2. Exclude the last character of string 'b' and find LCS of the remaining strings
        return dp[n][m] = max(longestCommonSubsequence(a, b, n - 1, m), longestCommonSubsequence(a, b, n, m - 1));
    }

    // Wrapper function to initialize the dp array and call the main function
    int findLCS(string a, string b) {
        int n = a.size();
        int m = b.size();

        // Initialize dp array with -1
        dp.assign(n + 1, vector<int>(m + 1, -1));

        // Call the main function to find the LCS length
        return longestCommonSubsequence(a, b, n, m);
    }
};

int main() {
    Solution solution;

    string a = "abcde";
    string b = "ace";

    int result = solution.findLCS(a, b);

    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
