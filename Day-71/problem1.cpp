#include <iostream>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, cnt0 = 0;
        for (auto a : s) {
            if (a == '1') cnt1++;
            else if (a == '0') cnt0++;
        }
        string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "010110";
    string result = sol.maximumOddBinaryNumber(s);
    cout << "Result: " << result << endl;
    return 0;
}
