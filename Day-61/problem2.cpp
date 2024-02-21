#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int countBit = 0;

        while(left != right){
            left >>= 1;
            right >>= 1;
            countBit++;
        }

        return (left << countBit);
    }
};

int main() {
    Solution sol;
    int left = 5;
    int right = 7;
    cout << "Bitwise AND of numbers in the range [" << left << ", " << right << "]: " << sol.rangeBitwiseAnd(left, right) << endl;
    return 0;
}
