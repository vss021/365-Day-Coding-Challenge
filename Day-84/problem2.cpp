#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to count the number of subarrays with a given sum
    int numSubarraysWithSum(vector<int>& nums, int targetSum) {
        // Map to store prefix sum frequency
        unordered_map<int, int> prefixSumFrequency({{0, 1}}); // Initialize with 0 sum count as 1
        int prefixSum = 0; // Initialize prefix sum
        int count = 0; // Initialize result count
        
        // Iterate through the array
        for (int num : nums) {
            prefixSum += num; // Update prefix sum
            
            // Check if there is a prefix sum whose difference with the current prefix sum equals the target sum
            count += prefixSumFrequency[prefixSum - targetSum];
            
            // Increment prefix sum frequency
            prefixSumFrequency[prefixSum]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int targetSum1 = 2;
    cout << "Number of subarrays with sum " << targetSum1 << " in nums1: " << sol.numSubarraysWithSum(nums1, targetSum1) << endl;

    // Example 2
    vector<int> nums2 = {0, 0, 0, 0, 0};
    int targetSum2 = 0;
    cout << "Number of subarrays with sum " << targetSum2 << " in nums2: " << sol.numSubarraysWithSum(nums2, targetSum2) << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int targetSum3 = 3;
    cout << "Number of subarrays with sum " << targetSum3 << " in nums3: " << sol.numSubarraysWithSum(nums3, targetSum3) << endl;

    return 0;
}
