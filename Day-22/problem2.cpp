#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        // Define a set of vowels.
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Initialize a counter for vowels.
        int vowelsCount = 0;
        
        // Calculate the index separating the two halves of the string.
        int midIndex = s.length() / 2;

        // Iterate through the first half of the string.
        for (int i = 0; i < midIndex; i++) {
            char charA = s[i];
            char charB = s[midIndex + i];
            
            // Check if the characters are vowels and update the count accordingly.
            if (vowels.count(charA)) vowelsCount++;
            if (vowels.count(charB)) vowelsCount--;
        }

        // Check if the count of vowels is zero, indicating both halves have the same number of vowels.
        return vowelsCount == 0;
    }
};

int main() {
    // Create an instance of the Solution class.
    Solution solution;

    // Test cases
    string test1 = "book";
    string test2 = "textbook";
    string test3 = "MerryChristmas";
    string test4 = "AbCdEfGh";

    // Check if halves are alike for each test case.
    cout << "Test 1: " << (solution.halvesAreAlike(test1) ? "True" : "False") << endl;
    cout << "Test 2: " << (solution.halvesAreAlike(test2) ? "True" : "False") << endl;
    cout << "Test 3: " << (solution.halvesAreAlike(test3) ? "True" : "False") << endl;
    cout << "Test 4: " << (solution.halvesAreAlike(test4) ? "True" : "False") << endl;

    return 0;
}