#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> charCount(26, 0);

        // Count the occurrences of characters in string s
        for (char c : s) {
            charCount[c - 'a']++;
        }

        string result;

        // Append characters from order in the order specified
        for (char c : order) {
            result.append(charCount[c - 'a'], c);
            charCount[c - 'a'] = 0;
        }

        // Append remaining characters in alphabetical order
        for (int i = 0; i < 26; ++i) {
            result.append(charCount[i], 'a' + i);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string order = "cbafed";
    string s = "abcdef";
    string sortedString = sol.customSortString(order, s);
    cout << "Sorted String: " << sortedString << endl;
    return 0;
}
