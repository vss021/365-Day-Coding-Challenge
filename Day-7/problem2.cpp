#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to get the length of the optimal compression of string 's' with at most 'k' deletions
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();

        // Initialize a 2D vector 'dp' of size (n+1) x (k+1) with initial value 9999
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 9999));

        // Base case: no characters and deletions
        dp[0][0] = 0;

        // Dynamic Programming loop
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int cnt = 0, del = 0;

                // Iterate from 'i' to 1 to count the frequency of characters and calculate deletions
                for (int l = i; l >= 1; l--) {
                    // Count the frequency of characters from 'i' to 'l'
                    if (s[l - 1] == s[i - 1])
                        cnt++;
                    else
                        del++;

                    // Check if the remaining allowed deletions are valid (j - del >= 0)
                    if (j - del >= 0) {
                        // Update the dp array based on the conditions
                        dp[i][j] = min(dp[i][j],
                            dp[l - 1][j - del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
                    }
                }

                // If there are remaining allowed deletions (j > 0), consider the case without deleting the current character
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }

        // Return the minimum length for 's' with at most 'k' deletions
        return dp[n][k];
    }
};



int main() {
    Solution solution;

    // Test case 1
    string s1 = "aaabcccd";
    int k1 = 2;
    cout << "Test Case 1: " << solution.getLengthOfOptimalCompression(s1, k1) << endl;

    // Test case 2
    string s2 = "aabbaa";
    int k2 = 0;
    cout << "Test Case 2: " << solution.getLengthOfOptimalCompression(s2, k2) << endl;

    // Test case 3
    string s3 = "abcdefghijklmnopqrstuvwxyz";
    int k3 = 10;
    cout << "Test Case 3: " << solution.getLengthOfOptimalCompression(s3, k3) << endl;

    return 0;
}
