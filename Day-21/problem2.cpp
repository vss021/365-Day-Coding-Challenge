#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string digitStack = "";

        for (char& currentDigit : num) {
            while (digitStack.size() > 0 && digitStack.back() > currentDigit && k > 0) {
                digitStack.pop_back();
                k--;
            }

            if (digitStack.size() > 0 || currentDigit != '0') {
                digitStack.push_back(currentDigit);
            }
        }

        while (digitStack.size() > 0 && k > 0) {
            digitStack.pop_back();
            k--;
        }

        if (digitStack.empty()) {
            return "0";
        }

        return digitStack;
    }
};


int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test cases
    string num1 = "1432219";
    int k1 = 3;
    cout << "Result 1: " << solution.removeKdigits(num1, k1) << endl;

    string num2 = "10200";
    int k2 = 1;
    cout << "Result 2: " << solution.removeKdigits(num2, k2) << endl;

    string num3 = "10";
    int k3 = 2;
    cout << "Result 3: " << solution.removeKdigits(num3, k3) << endl;

    string num4 = "123456789";
    int k4 = 3;
    cout << "Result 4: " << solution.removeKdigits(num4, k4) << endl;

    return 0;
}
