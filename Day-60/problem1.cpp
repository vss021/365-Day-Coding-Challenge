#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0) {
            if ((n & (n - 1)) == 0)
                return true;
        }
        return false;
    }

    bool isPowerOfTwo_alternative(int n) {
        if (n <= 0)
            return false;
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count == 1;
    }
    
};

int main() {
    Solution solution;

    // Test cases
    int test_cases[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 511, 1024};

    for (int num : test_cases) {
        cout << num << " is" << (solution.isPowerOfTwo(num) ? " " : " not ") << "a power of two.\n";
    }

    return 0;
}
