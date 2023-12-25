#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Recursive solution without memoization
    int numDecodingsRecursiveNoMemo(string& s, int index) {
        if (index == s.length()) {
            return 1; // Empty string is a valid decoding
        }

        if (s[index] == '0') {
            return 0; // A '0' cannot be decoded by itself
        }

        // Single-digit decoding
        int ways = numDecodingsRecursiveNoMemo(s, index + 1);

        // Two-digit decoding
        if (index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26) {
            ways += numDecodingsRecursiveNoMemo(s, index + 2);
        }

        return ways;
    }

    // Recursive solution with memoization
    int numDecodings(string s) {
        unordered_map<int, int> memo;
        return recursiveHelper(s, 0, memo);
    }

    // Tabulation solution
    int numDecodingsTabulation(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        if (s[0] != '0') {
            dp[1] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

private:
    // Recursive helper function with memoization
    int recursiveHelper(string& s, int index, unordered_map<int, int>& memo) {
        if (index == s.length()) {
            return 1; // Empty string is a valid decoding
        }

        if (s[index] == '0') {
            return 0; // A '0' cannot be decoded by itself
        }

        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // Single-digit decoding
        int ways = recursiveHelper(s, index + 1, memo);

        // Two-digit decoding
        if (index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26) {
            ways += recursiveHelper(s, index + 2, memo);
        }

        memo[index] = ways;
        return ways;
    }
};

int main() {
    Solution solution;

    // Example usage of recursive without memoization
    string s;
    cout << "Enter the encoded string: ";
    cin >> s;

    int waysRecursiveNoMemo = solution.numDecodingsRecursiveNoMemo(s, 0);
    cout << "Number of ways to decode (Recursive without Memoization): " << waysRecursiveNoMemo << endl;

    // Example usage of recursive with memoization
    int waysRecursive = solution.numDecodings(s);
    cout << "Number of ways to decode (Recursive with Memoization): " << waysRecursive << endl;

    // Example usage of tabulation
    int waysTabulation = solution.numDecodingsTabulation(s);
    cout << "Number of ways to decode (Tabulation): " << waysTabulation << endl;

    return 0;
}
