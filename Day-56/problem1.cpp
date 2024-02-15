#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // Sorting the input vector
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long perimeter = 0;
        long long sum = nums[0] + nums[1];  

        // Loop through the sorted numbers
        for (int i = 2; i < n; i++) {
            if (sum > nums[i])
                perimeter = sum + nums[i];
            
            // Increment the sum
            sum += nums[i];
        }     

        // If no valid perimeter is found, return -1
        return perimeter == 0 ? -1 : perimeter;
    }
};

int main() {
    // Example usage
    vector<int> nums = {3, 6, 2, 3}; // Sample input
    Solution solution;
    long long result = solution.largestPerimeter(nums);
    cout << "Largest perimeter: " << result << endl;

    return 0;
}
