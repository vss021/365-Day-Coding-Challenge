#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Time Complexity (TC): O(n)
    // Space Complexity (SC): O(1)
    
    int minimumLength(string s) {
        // Pointers i and j to traverse the string from both ends
        int i = 0;
        int j = s.size() - 1;

        // Continue traversing from both ends until they meet or find non-matching characters
        while (i < j && s[i] == s[j]) {
            char ch = s[i];

            // Move pointer i until it points to a different character
            while (i <= j && ch == s[i]) {
                ++i;
            }

            // Move pointer j until it points to a different character
            while (i <= j && ch == s[j]) {
                --j;
            }
        }

        // Length of remaining substring
        return j - i + 1;
    }
};

int main() {
    Solution sol;

    // Example usage
    string input = "racecar";
    int minLength = sol.minimumLength(input);
    cout << "Minimum length of remaining substring: " << minLength << endl;

    return 0;
}
