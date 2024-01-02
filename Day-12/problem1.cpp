#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> frequencyMap;
        int maxFrequency = INT_MIN;

        // Count the frequency of each number and find the maximum frequency
        for (const auto& num : nums) {
            frequencyMap[num]++;
            if (maxFrequency < frequencyMap[num]) {
                maxFrequency = frequencyMap[num];
            }
        }

        // Build the result matrix
        vector<vector<int>> resultMatrix;

        for (int i = 0; i < maxFrequency; ++i) {
            vector<int> currentRow;

            // Iterate through the frequency map and add numbers to the current row
            for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
                if (frequencyMap[it->first] > 0) {
                    currentRow.push_back(it->first);
                    frequencyMap[it->first]--;
                }
            }

            // Add the current row to the result matrix
            resultMatrix.push_back(currentRow);
        }

        return resultMatrix;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<vector<int>> result = solution.findMatrix(nums);

    // Display the result matrix
    for (const auto& row : result) {
        for (const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
