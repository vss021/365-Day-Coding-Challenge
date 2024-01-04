#include <iostream>
#include <vector>
using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    /*
        Function: minOperations

        Description:
        - Calculates the minimum number of operations needed to make all elements in the array divisible by 3.

        Approach:
        - Count the occurrences of each element in the array using an unordered_map.
        - Iterate through the map and calculate the operations required for each element.
        - Accumulate the total operations and return the result.

        Time Complexity: O(N)
        - N is the size of the input vector.

        Space Complexity: O(N)
        - Extra space is used for the unordered_map to store element occurrences.
    */
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> elementOccurrences;

        // Count the occurrences of each element in the array
        for (auto& num : nums) {
            elementOccurrences[num]++;
        }

        int totalOperations = 0;

        // Iterate through the element occurrences map
        for (auto& elementCount : elementOccurrences) {
            int occurrences = elementCount.second;

            // If an element occurs only once, it can't be made divisible by 3
            if (occurrences == 1) {
                return -1;
            }

            // Calculate the operations needed for the current element
            totalOperations += occurrences / 3;

            // If there are remaining occurrences, an additional operation is needed
            if (occurrences % 3) {
                totalOperations++;
            }
        }

        return totalOperations;
    }
};

int main() {
    // Example usage of minOperations function
    Solution solution;

    // Example input vector
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4, 4, 5, 6, 6};

    // Calculate the minimum operations
    int result = solution.minOperations(nums);

    // Display the result
    if (result != -1) {
        cout << "Minimum operations needed: " << result << endl;
    } else {
        cout << "Some elements occur only once. No solution possible." << endl;
    }

    return 0;
}
