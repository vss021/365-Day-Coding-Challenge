#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        unordered_map<char, int> charCount;

        int minWindowLength = INT_MAX;
        int startIdx = 0;

        // Initialize charCount with the character frequencies in string t
        for (char c : t)
            charCount[c]++;

        int requiredChars = charCount.size();
        int formedChars = 0;

        int leftIdx = 0, rightIdx = 0;

        while (rightIdx < sSize) {
            char currentChar = s[rightIdx];
            charCount[currentChar]--;

            if (charCount[currentChar] == 0)
                formedChars++;

            while (formedChars == requiredChars) {
                // Update minimum window length and starting index
                if (minWindowLength > rightIdx - leftIdx + 1) {
                    minWindowLength = rightIdx - leftIdx + 1;
                    startIdx = leftIdx;
                }

                // Move the left pointer to try to minimize the window
                char removedChar = s[leftIdx];
                charCount[removedChar]++;

                if (charCount[removedChar] > 0)
                    formedChars--;

                leftIdx++;
            }

            // Move the right pointer to expand the window
            rightIdx++;
        }

        // Check if a valid window was found
        if (minWindowLength != INT_MAX)
            return s.substr(startIdx, minWindowLength);
        else
            return "";
    }
};

#include <iostream>

int main() {
    Solution solution;

    // Example 1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    string result1 = solution.minWindow(s1, t1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    string s2 = "a";
    string t2 = "a";
    string result2 = solution.minWindow(s2, t2);
    cout << "Example 2: " << result2 << endl;

    // Example 3
    string s3 = "aa";
    string t3 = "aa";
    string result3 = solution.minWindow(s3, t3);
    cout << "Example 3: " << result3 << endl;

    return 0;
}
