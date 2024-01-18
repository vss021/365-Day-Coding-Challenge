#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Recursive Solution
    int climbStairsRecursive(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }

    // Memoization Solution
    int climbStairsMemoization(int n) {
        unordered_map<int, int> memo;
        return climbStairsMemoizationHelper(n, memo);
    }

    int climbStairsMemoizationHelper(int n, unordered_map<int, int>& memo) {
        if (n == 0 || n == 1) {
            return 1;
        }

        // Check if the result is already memoized
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        // If not, calculate and memoize the result
        memo[n] = climbStairsMemoizationHelper(n - 1, memo) + climbStairsMemoizationHelper(n - 2, memo);

        return memo[n];
    }

    // Iterative Solution
    int climbStairsIterative(int n) {
        if (n <= 1) {
            return n;
        }

        int ans;
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }

        return ans;
    }

    // Entry point for calling the memoization solution
    int climbStairs(int n) {
        return climbStairsMemoization(n);
    }
};

int main() {
    Solution solution;

    // Test the recursive solution
    int n_recursive = 5;
    int result_recursive = solution.climbStairsRecursive(n_recursive);
    cout << "Recursive solution: Number of ways to climb " << n_recursive << " stairs is " << result_recursive << "\n";

    // Test the memoization solution
    int n_memoization = 5;
    int result_memoization = solution.climbStairsMemoization(n_memoization);
    cout << "Memoization solution: Number of ways to climb " << n_memoization << " stairs is " << result_memoization << "\n";

    // Test the iterative solution
    int n_iterative = 5;
    int result_iterative = solution.climbStairsIterative(n_iterative);
    cout << "Iterative solution: Number of ways to climb " << n_iterative << " stairs is " << result_iterative << "\n";

    return 0;
}
