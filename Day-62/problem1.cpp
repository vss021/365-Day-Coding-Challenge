#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long Nsum = (n + 1) * n / 2;
        for(int x : nums)
            sum += x;
        return Nsum - sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << sol.missingNumber(nums) << endl;
    return 0;
}
