#include <iostream>
using namespace std;

class Solution {
public:
/*
    Approach:
    1. Initialize two vectors to store the first and last occurrences of each character (indexed from 'a' to 'z').
    2. Iterate through each character in the string.
    3. If it's the first occurrence of the character, update the first occurrence vector.
    4. If it's not the first occurrence, update the last occurrence vector and calculate the distance between the first and last occurrences.
    5. Update the maximum distance if the current distance is greater.
    6. Return the maximum distance between equal characters.
    */

    int maxLengthBetweenEqualCharacters(string s) {
        // Initialize vectors to store the first and last occurrences of each character
        vector<int> firstOccurrence(26, -1);
        vector<int> lastOccurrence(26, -1);

        // Variable to store the maximum length between equal characters
        int maxDistance = -1;

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); ++i) {
            int currentCharIndex = s[i] - 'a';

            // If it's the first occurrence of the character
            if (firstOccurrence[currentCharIndex] == -1) {
                firstOccurrence[currentCharIndex] = i;
            } else {
                // If it's not the first occurrence, update the last occurrence
                lastOccurrence[currentCharIndex] = i;

                // Calculate the distance between the first and last occurrences
                int distance = lastOccurrence[currentCharIndex] - firstOccurrence[currentCharIndex] - 1;

                // Update the maximum distance if the current distance is greater
                maxDistance = max(maxDistance, distance);
            }
        }

        // Return the maximum distance between equal characters
        return maxDistance;
    }
};


int main() {
    Solution solution;

    // Example string
    string inputString = "abca";

    // Call the function to find the maximum length between equal characters
    int result = solution.maxLengthBetweenEqualCharacters(inputString);

    // Display the result
    cout << "Maximum length between equal characters in \"" << inputString << "\" is: " << result << endl;

    return 0;
}
