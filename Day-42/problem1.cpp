#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        
        // Sorting the input array
        sort(nums.begin(), nums.end());

        // Iterating through the sorted array in increments of 3
        for (int i = 0; i < nums.size() - 2; i += 3) {
            // Checking the condition for the array of size 3
            if (nums[i + 2] - nums[i] <= k) {
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                // If the condition is not met, return an empty vector
                return {};
            }
        }

        return res;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {3, 1, 4, 7, 10, 12, 15};
    int k = 5;

    vector<vector<int>> result = solution.divideArray(nums, k);

    // Displaying the result
    if (result.empty()) {
        cout << "Unable to satisfy the conditions." << endl;
    } else {
        cout << "Arrays satisfying the conditions:" << endl;
        for (const auto& arr : result) {
            cout << "[";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
