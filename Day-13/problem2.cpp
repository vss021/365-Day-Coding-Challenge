#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // Approach: Sliding Window
    // Keep track of the latest positions of '0', '1', and '2'.
    // Whenever all three characters are found, update the answer by considering the current window.
    int smallestSubstring(string S) {
        int zero = -1;
        int one = -1;
        int two = -1;
        int ans = INT_MAX;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') {
                zero = i;
            }
            if (S[i] == '1') {
                one = i;
            }
            if (S[i] == '2') {
                two = i;
            }
            if (zero != -1 && one != -1 && two != -1) {
                ans = min(ans, i + 1 - min(zero, min(one, two)));
            }
        }
        if (ans != INT_MAX) {
            return ans;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Example usage
    string input = "1021101";
    int result = solution.smallestSubstring(input);

    cout << "Length of the smallest substring containing '0', '1', and '2': " << result << endl;

    return 0;
}
