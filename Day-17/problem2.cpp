#include <vector>
#include <unordered_map>
#include <iostream> // Include this if you want to print debugging information

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total_count = 0;

        // dp[i][diff] represents the number of arithmetic slices ending at index i
        // with a common difference of 'diff'
        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Calculate the difference and handle overflow
                long long diff = static_cast<long long>(nums[i]) - nums[j];

                if (diff > INT_MAX || diff < INT_MIN) {
                    continue; // Skip if the difference overflows an integer
                }

                int diff_int = static_cast<int>(diff);

                // Update the count of arithmetic slices with the current difference
                dp[i][diff_int] += 1;

                // Check if there are previous slices with the same difference
                if (dp[j].count(diff_int)) {
                    // Update the count and add to the total count
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};

    int result = solution.numberOfArithmeticSlices(nums);

    cout << "Number of Arithmetic Slices: " << result << endl;

    return 0;
}
