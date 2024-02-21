// mkdir Day-53 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Method 1: Hashing Approach
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int majorityElementHashing(vector<int>& nums) {
        // Create a hash map to store the count of each element
        unordered_map<int, int> countMap;
        
        // Iterate through the vector and count the occurrences of each element
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Find the element with count greater than n/2
        for (auto& pair : countMap) {
            if (pair.second > nums.size() / 2) {
                return pair.first; // Return the majority element
            }
        }
        
        return -1; // No majority element found
    }

    // Method 2: Sorting Approach
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)
    int majorityElementSorting(vector<int>& nums) {
        // Sort the vector
        sort(nums.begin(), nums.end());
        
        // Majority element will always be at index n/2 in a sorted array
        return nums[nums.size() / 2];
    }

    // Method 3: Boyer-Moore Majority Vote Algorithm
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int majorityElementBoyerMoore(vector<int>& nums) {
        int candidate = 0; // Initialize the candidate
        int count = 0; // Initialize the count of the candidate
        // Iterate through the vector
        for (int num : nums) {
            if (count == 0) {
                candidate = num; // Set the current element as the candidate
                count = 1; // Set the count to 1
            } else {
                if (num == candidate) {
                    count++; // Increment the count if the current element matches the candidate
                } else {
                    count--; // Decrement the count if the current element doesn't match the candidate
                }
            }
        }
        // Verifying if the candidate is the majority element
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++; // Counting the occurrences of the candidate
            }
        }
        // If the candidate occurs more than n/2 times, it's the majority element
        if (count > nums.size() / 2) {
            return candidate;
        } else {
            return -1; // No majority element found
        }
    }

    int majorityElement(vector<int>& nums) {

        // return majorityElementSorting(nums);
        // return majorityElementHashing(nums);
        
        return majorityElementBoyerMoore(nums);
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<int> nums1 = {3, 2, 3};
    cout << "Majority element: " << solution.majorityElement(nums1) << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element: " << solution.majorityElement(nums2) << endl;
    
    return 0;
}
