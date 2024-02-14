#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        int pos = 0, neg = 1;

        for (int num : nums) {
            if (num > 0) {
                ans[pos] = num;
                pos += 2;
            } else {
                ans[neg] = num;
                neg += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, -3, 5, -7, 9}; // Example input

    // Call the rearrangeArray function
    vector<int> result = sol.rearrangeArray(nums);

    // Display the rearranged array
    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
