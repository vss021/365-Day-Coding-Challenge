#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int atoi(string s) {
        int n = s.size();
        int ans = 0;
        int sign = 1;

        for(int i = n-1; i >= 0; i--) {
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9) {
                ans += (s[i]-'0') * pow(10, n - 1 - i);
            } else if(s[i] == '-' && i == 0) {
                sign = -1;
                break;
            } else {
                return -1;
            }
        }

        return ans * sign;
    }
};

int main() {
    Solution solution;

    // Example usage
    string input = "123";
    int result = solution.atoi(input);

    // Print the result
    cout << "Converted integer: " << result << endl;

    return 0;
}
