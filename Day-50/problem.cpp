#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        vector<int> result; // Vector to store the largest divisible subset
        sort(nums.begin(), nums.end()); // Sorting the input array

        // Vector to store the length of the largest divisible subset ending at each index
        vector<int> dp(n, 1);

        int maxSubsetLength = 1; // Length of the largest divisible subset
        int lastNumber = -1; // Last number added to the subset

        // Dynamic programming approach to find the length of the largest divisible subset
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (maxSubsetLength < dp[i]) {
                        maxSubsetLength = dp[i];
                    }
                }
            }
        }

        // Reconstructing the largest divisible subset
        for (int i = n - 1; i >= 0; i--) {
            if (maxSubsetLength == dp[i] && (lastNumber == -1 || lastNumber % nums[i] == 0)) {
                result.push_back(nums[i]); // Adding the number to the subset
                maxSubsetLength--;
                lastNumber = nums[i];
            }
        }

        reverse(result.begin(), result.end()); // Reversing the result vector
        return result;
    }
};

int main() {
    Solution solution;

    // Example input array
    vector<int> nums = {1, 2, 3, 4, 6, 8};

    // Finding the largest divisible subset
    vector<int> result = solution.largestDivisibleSubset(nums);

    // Displaying the result
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
