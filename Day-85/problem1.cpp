#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        ans[0] = 1;

        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int right = 1;

        for(int i=n-1; i>=0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test the productExceptSelf method
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Result:";
    for (int num : result) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
