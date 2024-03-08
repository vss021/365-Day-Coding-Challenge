#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time Complexity: O(n), where n is the number of elements in the input vector
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        int maxFrequency = -1;

        // Count frequencies of elements
        for (auto num : nums) {
            if (frequencyMap.find(num) != frequencyMap.end()) {
                maxFrequency = max(maxFrequency, frequencyMap[num] + 1);
                frequencyMap[num]++;
            } else {
                frequencyMap[num] = 1;
            }
        }

        int result = 0;

        // If all elements have distinct frequencies, return the number of elements
        if (nums.size() == frequencyMap.size()) {
            return nums.size();
        }

        // Count elements with maximum frequency
        for (auto entry : frequencyMap) {
            if (entry.second == maxFrequency) {
                result += maxFrequency;
            }
        }

        return result;
    }

    // Time Complexity: O(n log n), where n is the number of elements in the input vector
    int maxFrequencyElements_Sorting(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n log n) complexity
        int maxFrequency = 0, currentFrequency = 1, maxElements = 0;

        // Count frequency of elements after sorting
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                currentFrequency++;
            } else {
                maxFrequency = max(maxFrequency, currentFrequency);
                currentFrequency = 1;
            }
        }
        maxFrequency = max(maxFrequency, currentFrequency);

        // Count the number of elements with the maximum frequency
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                currentFrequency++;
            } else {
                currentFrequency = 1;
            }

            if (currentFrequency == maxFrequency) {
                maxElements += currentFrequency;
            }
        }

        return maxElements;
    }
};

// Test cases and sample input
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 3, 3, 3}; // Sample Input (SP)
    cout << "Test Case 1: " << solution.maxFrequencyElements(nums1) << endl; // Expected Output: 6
    cout << "Test Case 1 (Sorting): " << solution.maxFrequencyElements_Sorting(nums1) << endl; // Expected Output: 6

    vector<int> nums2 = {1, 4, 8, 8, 4, 1}; // Sample Input (SP)
    cout << "Test Case 2: " << solution.maxFrequencyElements(nums2) << endl; // Expected Output: 5
    cout << "Test Case 2 (Sorting): " << solution.maxFrequencyElements_Sorting(nums2) << endl; // Expected Output: 5

    vector<int> nums3 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5}; // Sample Input (SP)
    cout << "Test Case 3: " << solution.maxFrequencyElements(nums3) << endl; // Expected Output: 10
    cout << "Test Case 3 (Sorting): " << solution.maxFrequencyElements_Sorting(nums3) << endl; // Expected Output: 10

    vector<int> nums4 = {1, 2, 3, 4, 5}; // Sample Input (SP)
    cout << "Test Case 4: " << solution.maxFrequencyElements(nums4) << endl; // Expected Output: 1
    cout << "Test Case 4 (Sorting): " << solution.maxFrequencyElements_Sorting(nums4) << endl; // Expected Output: 1

    return 0;
}
