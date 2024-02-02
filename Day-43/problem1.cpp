#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for (int i = 1; i <= 9; ++i) {
            int num = i;

            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;

                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        // Sort the result vector
        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution solution;

    // Example usage
    int low = 100;
    int high = 3000;

    vector<int> result = solution.sequentialDigits(low, high);

    // Print the result
    cout << "Sequential digits between " << low << " and " << high << ": ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
