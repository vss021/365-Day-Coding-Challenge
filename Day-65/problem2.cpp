#include <iostream>

using namespace std;

class Solution {
public:
    int maxSum(int n) {
        int sum = n / 2 + n / 3 + n / 4;

        int twoSum = 0;
        int threeSum = 0;
        int fourSum = 0;

        if (sum > n) {
            twoSum = maxSum(n / 2);
            threeSum = maxSum(n / 3);
            fourSum = maxSum(n / 4);
        }

        return max((twoSum + threeSum + fourSum), n);
    }
};

int main() {
    Solution solution;

    // Example usage
    int n = 12;
    int maxSum = solution.maxSum(n);

    cout << "Max sum for n = " << n << " is: " << maxSum << endl;

    return 0;
}
