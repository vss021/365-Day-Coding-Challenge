#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    int dp[100][901]; // Assuming maximum size for better readability

    // Recursive helper function with memoization
    int countSubsequences(string &s, int currentIndex, int previousSum) {
        // Base case: reached the end of the string
        if (currentIndex == s.size()) {
            return 1;
        }

        // Memoization check
        if (dp[currentIndex][previousSum] != -1) {
            return dp[currentIndex][previousSum];
        }

        int currentSum = 0;
        int totalCount = 0;

        // Try all possible subsequences starting from the current index
        for (int nextIndex = currentIndex; nextIndex < s.size(); nextIndex++) {
            currentSum += (s[nextIndex] - '0');

            // If the current sum is greater than or equal to the previous sum,
            // recursively explore the rest of the string
            if (currentSum >= previousSum) {
                totalCount += countSubsequences(s, nextIndex + 1, currentSum);
            }
        }

        // Memoize and return the total count
        return dp[currentIndex][previousSum] = totalCount;
    }

public:
    int TotalCount(string str) {
        // Initialize the memoization table with -1
        memset(dp, -1, sizeof dp);

        // Start the recursive counting process from the beginning of the string
        return countSubsequences(str, 0, 0);
    }
};

int main() {
    Solution solution;

    // Example string
    string inputString = "123";

    // Calculate and print the total count of valid subsequences
    int totalCount = solution.TotalCount(inputString);
    cout << "Total Count of Valid Subsequences: " << totalCount << endl;

    return 0;
}
