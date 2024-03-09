#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Binary search method
    // TC: O(log n), SC: O(1)
    bool binarySearch(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    // Method using unordered set
    // TC: O(m + n), SC: O(n)
    int getCommonUsingSet(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums2.begin(), nums2.end());

        for (int num : nums1) {
            if (set.find(num) != set.end()) {
                return num;
            }
        }
        return -1;
    }

public:
    // Method using binary search
    // TC: O(m * log n), SC: O(1)
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            if (binarySearch(nums2, num)) {
                return num;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3, 1, 4, 6, 5};
    vector<int> nums2 = {5, 2, 7, 8, 4};

    int commonElement = solution.getCommon(nums1, nums2);

    if (commonElement != -1) {
        cout << "Common element: " << commonElement << endl;
    } else {
        cout << "No common element found" << endl;
    }

    return 0;
}
