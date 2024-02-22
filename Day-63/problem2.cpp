#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solveByRecursiveApproach(string s, string t, int si, int ti, int sn, int tn) {
        // Base case
        if (ti == tn) {
            return 1;
        }
        if (si >= sn) {
            return 0;
        }

        // If current characters match
        if (s[si] == t[ti]) {
            // Two options: include current character of s or exclude it
            return (solveByRecursiveApproach(s, t, si + 1, ti + 1, sn, tn) + solveByRecursiveApproach(s, t, si + 1, ti, sn, tn)) % int(1e9 + 7);
        } else {
            // Current characters don't match, move to the next character of s
            return solveByRecursiveApproach(s, t, si + 1, ti, sn, tn) % int(1e9 + 7);
        }
    }


    int solveByMemoization(string &s, string &t, vector<vector<int>> &memo, int si, int ti) {
        // Base case
        if (ti == t.size()) {
            return 1;
        }
        if (si >= s.size()) {
            return 0;
        }

        // If the result is already calculated, return it from memoization
        if (memo[si][ti] != -1) {
            return memo[si][ti];
        }

        int result;
        // If current characters match
        if (s[si] == t[ti]) {
            // Two options: include current character of s or exclude it
            result = (solveByMemoization(s, t, memo, si + 1, ti + 1) + solveByMemoization(s, t, memo, si + 1, ti)) % MOD;
        } else {
            // Current characters don't match, move to the next character of s
            result = solveByMemoization(s, t, memo, si + 1, ti);
        }

        // Store the result in memoization array
        memo[si][ti] = result;
        return result;
    }

    int subsequenceCount(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        // Initialize memoization array with -1
        vector<vector<int>> memo(sn, vector<int>(tn, -1));

        return solveByMemoization(s, t, memo, 0, 0);
    }
};

int main() {
    Solution solution;
    string s = "abcabc";
    string t = "abc";
    cout << solution.subsequenceCount(s, t) << endl;  // Output should be 4
    return 0;
}
