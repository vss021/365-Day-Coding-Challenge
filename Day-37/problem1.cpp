#include <iostream>

#include <vector>
using namespace std;


class Solution {
private:
    int mod = int(1e9 + 7);

public:
    int kInversePairs(int n, int k) {
        // Initialize two vectors to store the previous and current dynamic programming states
        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        // Set the base case for 0 inverse pairs
        prev[0] = curr[0] = 1;

        // Iterate through each value of N (size of the array)
        for (int N = 1; N <= n; ++N) {
            // Iterate through each value of K (number of inverse pairs)
            for (int K = 0; K <= k; ++K) {
                // Calculate the current state using the recurrence relation
                curr[K] = (prev[K] + (K > 0 ? curr[K - 1] : 0)) % mod;
                curr[K] = (curr[K] + mod - (K >= N ? prev[K - N] : 0)) % mod;
            }

            // Update the previous state with the current state for the next iteration
            prev = curr;
        }

        // The result is stored in the last element of the 'curr' vector for k inverse pairs
        return curr[k];
    }
};


int main() {
    Solution solution;

    // Example usage
    int n = 3;
    int k = 1;

    int result = solution.kInversePairs(n, k);

    cout << "The number of arrays with " << k << " inverse pairs for size " << n << " is: " << result << endl;

    return 0;
}
