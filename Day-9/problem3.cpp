#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
// Bruteforce Approach 
vector<vector<int>> fourSumBruteforce(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        for (int a = 0; a < n - 3; ++a) {
            for (int b = a + 1; b < n - 2; ++b) {
                for (int c = b + 1; c < n - 1; ++c) {
                    for (int d = c + 1; d < n; ++d) {
                        if (nums[a] + nums[b] + nums[c] + nums[d] == target) {
                            result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        }
                    }
                }
            }
        }

        return result;
    }


// Backtracking solution 

    void findQuadruplets(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    // Base case: Check if we have found a valid quadruplet
    if (current.size() == 4 && accumulate(current.begin(), current.end(), 0) == target) {
        result.push_back(current);
        return;
    }

    // Recursive case: Explore all possible combinations
    for (int i = start; i < nums.size(); i++) {
        // Avoid duplicates
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }

        // Backtracking: Include the current element in the combination
        current.push_back(nums[i]);

        // Recursive call with the updated combination and the next index
        findQuadruplets(nums, target, i + 1, current, result);

        // Backtracking: Exclude the current element from the combination
        current.pop_back();
    }
}





    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for j
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long newTarget = static_cast<long long>(target) - nums[i] - nums[j];
                int low = j + 1, high = n - 1;

                while (low < high) {
                    int sum = nums[low] + nums[high];

                    if (sum < newTarget) {
                        ++low;
                    } else if (sum > newTarget) {
                        --high;
                    } else {
                        // Found a valid quadruplet
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});

                        // Skip duplicate values for low and high
                        int tempLow = low, tempHigh = high;
                        while (low < high && nums[low] == nums[tempLow]) {
                            ++low;
                        }
                        while (low < high && nums[high] == nums[tempHigh]) {
                            --high;
                        }
                    }
                }

                // Skip duplicate values for j
                while (j + 1 < n && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }

            // Skip duplicate values for i
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return output;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;

    // Brute-force approach
    cout << "Brute-force approach:" << endl;
    vector<vector<int>> resultBruteforce = solution.fourSumBruteforce(nums, target);
    for (const auto& quadruplet : resultBruteforce) {
        cout << "[ ";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    // Backtracking approach
    cout << "\nBacktracking approach:" << endl;
    vector<vector<int>> resultBacktracking = solution.fourSum(nums, target);
    for (const auto& quadruplet : resultBacktracking) {
        cout << "[ ";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
