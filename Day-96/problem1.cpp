#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Mark all out-of-range values as n+1
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n+1;
                continue;
            }
        }
        // Mark all ranged valued indices as negative
        for(int i = 0; i < n; i++) {
            if(abs(nums[i]) >= n+1) continue;
            int val = abs(nums[i]);
            nums[val-1] = -1 * abs(nums[val-1]);
        }
        // If any ranged valued index is positive, return one plus its index since it is 1-indexed
        for(int i = 0; i < n; i++)
            if(nums[i] > 0) return i+1;
        return n+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    int result = sol.firstMissingPositive(nums);
    cout << "The smallest missing positive integer is: " << result << endl;
    return 0;
}
