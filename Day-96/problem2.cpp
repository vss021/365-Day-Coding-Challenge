#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAdditiveSequence(string s) {
        int n = s.length();
        // First number
        int num1 = 0;
        // At most the first number will contain n/2 digits, so looping against it
        for(int i = 0; i < n/2; i++) {
            // Finding the first number
            num1 = num1 * 10 + (s[i] - '0');
            // Going for the second number
            int num2 = 0;
            // Search for the second number starts from the next index, hence i + 1th index
            for(int j = i + 1; j < n - 1; j++) {
                // Assigning the value to the second number
                num2 = num2 * 10 + (s[j] - '0');
                int prev2 = num1, prev1 = num2;
                // Now finding the third number which can satisfy the equation of num1 + num2 = num
                int num = 0;
                int k = j + 1;
                while(k < n) {
                    num = num * 10 + (s[k] - '0');
                    if(num == (prev1 + prev2)) {
                        prev2 = prev1;
                        prev1 = num;
                        num = 0;
                    }
                    k++;
                }
                if (k == n && num == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "112358";
    bool result = sol.isAdditiveSequence(s);
    if(result) {
        cout << "The string contains an additive sequence." << endl;
    } else {
        cout << "The string does not contain an additive sequence." << endl;
    }
    return 0;
}
