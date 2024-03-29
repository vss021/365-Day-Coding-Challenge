#include <iostream>
#include <cstring> // for memset
using namespace std;

class Solution {
public:
    int N1, N2, N3;
    int dp[21][21][21];

    int maxCommonSeq(int i, int j, int k, string A, string B, string C) {
        if (i >= N1 || j >= N2 || k >= N3) {
            return 0;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        if (A[i] == B[j] && B[j] == C[k]) {
            return dp[i][j][k] = 1 + maxCommonSeq(i + 1, j + 1, k + 1, A, B, C);
        }

        int a = maxCommonSeq(i + 1, j, k, A, B, C);
        int b = maxCommonSeq(i, j + 1, k, A, B, C);
        int c = maxCommonSeq(i, j, k + 1, A, B, C);
        int d = maxCommonSeq(i + 1, j + 1, k, A, B, C);
        int e = maxCommonSeq(i + 1, j, k + 1, A, B, C);
        int f = maxCommonSeq(i, j + 1, k + 1, A, B, C);

        return dp[i][j][k] = max({a, b, c, d, e, f});
    }

    int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
        N1 = n1;
        N2 = n2;
        N3 = n3;

        // Initialize the memoization table with -1
        memset(dp, -1, sizeof(dp));

        // Call the helper function to find the length of the LCS
        return maxCommonSeq(0, 0, 0, A, B, C);
    }
};

int main() {
    Solution solution;

    // Example strings A, B, and C
    string A = "AGGT12";
    string B = "12TXAYB";
    string C = "12XBA";

    int result = solution.LCSof3(A, B, C, A.size(), B.size(), C.size());

    // Display the length of the longest common subsequence
    cout << "Length of the Longest Common Subsequence: " << result << endl;

    return 0;
}
