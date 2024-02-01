#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s) {
        // Convert the string to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        unordered_map<char, int> ump;
        
        // Count occurrences of each alphabet in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ump[s[i]]++;
            }
        }
        
        // Check if all 26 alphabets are present
        return ump.size() == 26;
    }
};

int main() {
    // Example usage
    Solution solution;
    string testString = "The quick brown fox jumps over the lazy dog";

    bool isPangram = solution.checkPangram(testString);

    // Displaying the result
    if (isPangram) {
        cout << "The string is a Pangram." << endl;
    } else {
        cout << "The string is not a Pangram." << endl;
    }

    return 0;
}
