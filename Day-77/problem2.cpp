#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Solution using recursion with memoization
    bool isMatch(string s, string p) {
        // Initialize memoization table
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        // Call helper function with memoization
        return helper(s, p, 0, 0, memo);
    }

private:
    // Helper function for recursion with memoization
    bool helper(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
        // Check if result for this state is already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // Base cases
        if (j == p.length())
            return memo[i][j] = (i == s.length());

        if (i == s.length())
            return memo[i][j] = (p[j] == '*' && helper(s, p, i, j + 1, memo));

        // Check if current characters match or if p[j] is '?'
        bool first_match = (p[j] == '?' || p[j] == s[i]);

        // Handle wildcard '*'
        if (p[j] == '*') {
            return memo[i][j] = (helper(s, p, i + 1, j, memo) || helper(s, p, i, j + 1, memo));
        } else {
            // Move to the next characters in s and p
            return memo[i][j] = (first_match && helper(s, p, i + 1, j + 1, memo));
        }
    }

    // Solution using iterative dynamic programming
    bool isMatchDP(string s, string p) {
        int m = s.size(), n = p.size();
        // Initialize dynamic programming table
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns starting with '*'
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        // Fill the dynamic programming table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }

    // Solution using a greedy approach
    bool isMatchGreedy(string s, string p) {
        int s_index = 0, p_index = 0, match_index = 0, star_index = -1;
        
        // Greedy matching
        while (s_index < s.size()) {
            if (p_index < p.size() && (p[p_index] == '?' || p[p_index] == s[s_index])) {
                ++s_index;
                ++p_index;
            } else if (p_index < p.size() && p[p_index] == '*') {
                star_index = p_index;
                match_index = s_index;
                ++p_index;
            } else if (star_index != -1) {
                p_index = star_index + 1;
                match_index++;
                s_index = match_index;
            } else {
                return false;
            }
        }
        
        // Skip any '*'s remaining in the pattern
        while (p_index < p.size() && p[p_index] == '*') {
            ++p_index;
        }
        
        // Check if the pattern is fully matched
        return p_index == p.size();
    }
};

int main() {
    Solution sol;
    // Test all three solutions
    cout << sol.isMatch("acdcb", "a*c?b") << endl; // Output: true
    cout << sol.isMatchDP("acdcb", "a*c?b") << endl; // Output: true
    cout << sol.isMatchGreedy("acdcb", "a*c?b") << endl; // Output: true
    return 0;
}
