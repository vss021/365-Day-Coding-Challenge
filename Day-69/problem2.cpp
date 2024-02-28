#include <iostream>
using namespace std;

class Solution {
public:
    int DivisibleByEight(string s) {
        int n = s.size();
        if (n > 3) {
            s = s.substr(n - 3, 3);
        }
        if (stoi(s) % 8 == 0) {
            return 1;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution solution;
    
    // Test cases
    cout << "Test Case 1: " << solution.DivisibleByEight("1234") << endl; // Output: -1
    cout << "Test Case 2: " << solution.DivisibleByEight("1248") << endl; // Output: 1
    cout << "Test Case 3: " << solution.DivisibleByEight("112233") << endl; // Output: 1
    cout << "Test Case 4: " << solution.DivisibleByEight("123456789") << endl; // Output: -1
    
    return 0;
}
