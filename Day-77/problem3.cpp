#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestSubstring(string S, int N) {
        int maxLen = 0;
        string ans = "-1";
        int i = 0, j = 0;

        // Iterate over the string
        while (i < N && j < N) {
            // Extract substring from i to j
            string subString = S.substr(i, j - i + 1);

            // Check if the substring occurs again in the string
            if (S.find(subString, j + 1) != string::npos) {
                // If found, update maxLen and ans if necessary
                int len = subString.length();
                if (len > maxLen) {
                    maxLen = len;
                    ans = subString;
                }
            } else {
                // If not found, move the starting pointer i forward
                i++;
            }
            // Move the ending pointer j forward
            j++;
        }
        // Return the longest repeating non-overlapping substring
        return ans;
    }
};

int main() {
    Solution sol;
    // Test the longestSubstring function
    string input = "abhihiab";
    int length = input.length();
    cout << sol.longestSubstring(input, length) << endl; // Output: "ab"
    return 0;
}
