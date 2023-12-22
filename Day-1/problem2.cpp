#include <iostream>
using namespace std;

class Solution {
public:
    /*
        Approach:
        - Initialize variables for max_score, count_zeros_left, and count_ones_right.
        - Iterate through the string:
            - Update count_zeros_left and count_ones_right based on the current character.
            - Update max_score with the maximum of count_zeros_left + count_ones_right.
        - Return the max_score.
    */
    int maxScore(string& s) {
        int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};

int main() {
    // Create an instance of the Solution class.
    Solution solution;

    // Test the maxScore function with a sample string.
    string inputString = "011101";
    int result = solution.maxScore(inputString);

    // Display the result.
    cout << "Maximum Score: " << result << endl;

    return 0;
}
