#include <iostream>

// Include necessary headers for Solution class
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> m1;
        map<char, int> m2;

        // Check if the lengths of the two strings are equal
        if (word1.length() != word2.length())
            return false;

        // Maintain the frequencies of characters in both word1 and word2
        for (int i = 0; i < word1.length(); i++) {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        // Vectors to store the frequencies of two strings
        vector<int> v1, v2;

        // Extract frequencies from the map
        for (auto i : m1) {
            v1.push_back(i.second);
        }
        for (auto i : m2) {
            v2.push_back(i.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        // Vectors to store all the alphabets used in the strings
        vector<char> v3, v4;

        // Extract characters from the map
        for (auto i : m1) {
            v3.push_back(i.first);
        }
        for (auto i : m2) {
            v4.push_back(i.first);
        }
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());

        // Check three conditions
        // 1. If the size of two strings is equal (already checked above)
        // 2. The characters occurring in word1 must also be present in word2, irrespective of frequencies.
        // 3. The set of frequencies of characters in word1 should be equal to the set of frequencies of the characters in word 2.
        return (v1 == v2 && v3 == v4);
    }
};

int main() {
    // Example words
    string word1 = "abcabc";
    string word2 = "bcaabc";

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the closeStrings function
    bool result = solution.closeStrings(word1, word2);

    // Displaying the result
    if (result) {
        cout << "The words are close strings." << endl;
    } else {
        cout << "The words are not close strings." << endl;
    }

    return 0;
}
