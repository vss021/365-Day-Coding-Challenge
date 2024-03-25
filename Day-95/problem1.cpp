#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> set;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(set.find(nums[i]) != set.end()) {
                result.push_back(nums[i]);
            } else {
                set.insert(nums[i]);
            }
        } 

        return result;
    }
};

int main() {
    // Example usage for findDuplicates function
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution solution;
    vector<int> duplicates = solution.findDuplicates(nums);

    cout << "Duplicate elements in the array: ";
    for(int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
