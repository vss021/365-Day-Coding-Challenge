#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int kSubstrConcat(int n, string& s, int k) {
        // Check if it's possible to divide the string into substrings of length 'k'
        if (n % k != 0) {
            return 0;
        }

        // Use a set to store unique substrings
        set<string> uniqueSubstrings;

        // Iterate through the string, extracting substrings of length 'k'
        for (int i = 0; i < n; i += k) {
            // Insert the substring into the set
            uniqueSubstrings.insert(s.substr(i, k));
        }

        // Check if the number of unique substrings is at most 2
        return uniqueSubstrings.size() <= 2;
    }
};

int main() {
    Solution solution;

    // Example Usage
    int n = 8;
    string s = "abcabcab";
    int k = 3;

    int result = solution.kSubstrConcat(n, s, k);

    cout << "Result: " << result << endl;

    return 0;
}
