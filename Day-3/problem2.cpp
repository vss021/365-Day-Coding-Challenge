#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Initialize a variable to store the character at index 0.
     * - Calculate the minimum operations for two scenarios:
     *   1. Starting with the character at index 0.
     *   2. Starting with the opposite character of the one at index 0.
     * - Return the minimum of the two scenarios.
     */
    int minOperations(string s) {
        char startingChar = s[0];

        // Calculate the minimum operations starting with the character at index 0.
        int count1 = countAlternations(s, startingChar);

        // Calculate the minimum operations starting with the opposite character of the one at index 0.
        int count2 = countAlternations(s, (startingChar == '0') ? '1' : '0') + 1;

        // Return the minimum of the two scenarios.
        return min(count1, count2);
    }

private:
    /**
     * Helper function to count the number of alternations needed in the string.
     */
    int countAlternations(string s, char startingChar) {
        int count = 0;
        
        // Iterate through the string starting from index 1.
        for (int i = 1; i < s.length(); i++) {
            char currentChar = s[i];

            // If the current character is equal to the previous character, increment the count.
            if (currentChar == startingChar) {
                count++;

                // Toggle the starting character.
                startingChar = (startingChar == '0') ? '1' : '0';
            } else {
                // If the characters are different, update the starting character.
                startingChar = currentChar;
            }
        }

        return count;
    }
};

int main() {
    // Example usage
    Solution solution;
    string input = "010101";
    cout << "Minimum operations: " << solution.minOperations(input) << endl;

    return 0;
}
