#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        // Initialize a vector to store the count of occurrences of each number
        vector<int> count(n + 1, 0);

        // Variables to store the missing and duplicate numbers
        int missing = 0, duplicate = 0;

        // Count the occurrences of each number in the input vector
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        // Find the duplicate and missing numbers based on the counts
        for (int i = 1; i < count.size(); i++) {
            if (count[i] == 2) {
                duplicate = i;
            }
            if (count[i] == 0) {
                missing = i;
            }
        }

        // Return a vector containing the duplicate and missing numbers
        return {duplicate, missing};
    }
};




int main() {
    // Example usage
    
    vector<int> nums = {1, 2, 2, 4};  // Replace with your input

    // Create an instance of the Solution class
    Solution solution;

    // Call the findErrorNums function
    vector<int> result = solution.findErrorNums(nums);

    // Display the result
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
