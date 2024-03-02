#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Solution 1: Sorting after squaring
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }

    // Solution 2: Two pointers
    vector<int> sortedSquaresTwoPointers(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0, right = n - 1; // Pointers for two ends of the array
        int index = n - 1; // Index for filling the result array from the end

        // Loop from end to start
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            // Compare squares of elements at left and right pointers
            // Fill the result array accordingly from end to start
            if (leftSquare > rightSquare) {
                result[index--] = leftSquare;
                left++;
            } else {
                result[index--] = rightSquare;
                right--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example usage with Solution 1
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result1 = sol.sortedSquares(nums);
    cout << "Solution 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example usage with Solution 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    vector<int> result2 = sol.sortedSquaresTwoPointers(nums2);
    cout << "Solution 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
