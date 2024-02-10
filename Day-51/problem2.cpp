#include <string>

using namespace std;

class Solution {
private:
    string t;

    // Function to check and count palindromes with given left and right indices
    int check(int left, int right, int count = 0) {
        while (left >= 0 && right < t.size()) {
            if (t[left--] == t[right++]) 
                count++; // Increment count if characters match
            else 
                break; // Break the loop if characters don't match
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        t = s; // Assign s to t

        // Loop through each character of the string
        for (int i = 0; i < n; i++) {
            // Count odd-length palindromes with center at i
            count += check(i, i);

            // Count even-length palindromes with center at i and i+1
            count += check(i, i + 1);
        }

        return count;
    }
};


int main() {
    // Example usage
    Solution solution;

    // Input string
    string input = "abc"; // Change input string as needed

    // Calculate the count of palindromic substrings
    int count = solution.countSubstrings(input);
    
    // Output the result
    cout << "Number of palindromic substrings in \"" << input << "\": " << count << endl;

    return 0;
}
