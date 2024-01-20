#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        stack<int> st;
        long sumOfMinimums = 0;

        // Traverse the array and calculate the sum of minimums
        for (int i = 0; i <= arr.size(); i++) {
            // Process the stack to find the minimum element and calculate the sum
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                
                // Determine left and right boundaries of the subarray
                int leftBoundary = st.empty() ? -1 : st.top();
                int rightBoundary = i;

                // Calculate the count of subarrays with arr[mid] as the minimum element
                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                // Update the sum of minimums with the contribution of the current subarray
                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            
            // Push the current index onto the stack
            st.push(i);
        }

        // Return the sum of minimums as an integer
        return static_cast<int>(sumOfMinimums);
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;

    // Example array
    vector<int> arr = {3, 1, 2, 4};

    // Call the sumSubarrayMins function and print the result
    int result = solution.sumSubarrayMins(arr);

    cout << "Sum of minimums of all subarrays: " << result << endl;

    return 0;
}
