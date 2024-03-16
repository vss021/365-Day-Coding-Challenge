#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxi;
    }

};

int main() {
    Solution solution;

    // Example usage for problem 1: Maximum Length of Contiguous Subarray with Equal 0s and 1s
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    int maxLength = solution.findMaxLength(nums);
    cout << "Maximum length of contiguous subarray with equal 0s and 1s: " << maxLength << endl;

    return 0;
}
