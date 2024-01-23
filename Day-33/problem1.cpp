#include <vector>
#include <string>
#include <unordered_set>

#include <iostream>
using namespace std;


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        backTrack(arr, "", 0, maxLength);
        return maxLength;
    }

private:
    void backTrack(vector<string>& arr, string current, int start, int& maxLength) {
        // Update maxLength if the current combination has a greater length
        if (maxLength < current.length())
            maxLength = current.length();

        // Explore all possibilities starting from the 'start' index
        for (int i = start; i < arr.size(); i++) {
            // Check if adding arr[i] to the current combination is valid
            if (isValid(current, arr[i]))
                backTrack(arr, current + arr[i], i + 1, maxLength);
        }
    }

    bool isValid(string& currentString, string& newString) {
        unordered_set<char> charSet;

        // Check each character in newString for validity
        for (char ch : newString) {
            // If the character is already in charSet, the combination is invalid
            if (charSet.count(ch) > 0) {
                return false;
            }

            // Add the character to charSet
            charSet.insert(ch);

            // If the character is already in currentString, the combination is invalid
            if (currentString.find(ch) != string::npos) {
                return false;
            }
        }

        // If no issues found, the combination is valid
        return true;
    }
};


int main() {
    Solution solution;

    // Example usage with a vector of strings
    vector<string> input = {"abc", "def", "gh", "ijk"};
    int result = solution.maxLength(input);

    // Print the result
    cout << "Maximum Length: " << result << endl;

    return 0;
}

