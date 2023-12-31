#include <iostream>

// RECURSION
class Solution {
public:
    // Helper function for recursion
    bool recursiveFunction(int* coins, int i, int sum) {
        // Base case
        if (i < 0) {
            if (sum != 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024))
                return true;
            else
                return false;
        }

        if (sum != 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024))
            return true;

        // Recursive calls
        // Small calculation
        bool a = recursiveFunction(coins, i - 1, sum);
        if (a)
            return true;

        bool b = recursiveFunction(coins, i - 1, sum + coins[i]);
        return b;
    }

    // Function to check if it is possible to make a sum divisible by 20, 24, or equal to 2024 using coins
    int isPossible(int N, int coins[]) {
        return recursiveFunction(coins, N - 1, 0);
    }
};


int main() {
    Solution solution;

    // Example array of coins
    int coins[] = {10, 15, 25, 30};

    // Get the size of the coins array
    int N = sizeof(coins) / sizeof(coins[0]);

    // Check if it is possible to make a sum divisible by 20, 24, or equal to 2024 using coins
    bool result = solution.isPossible(N, coins);

    // Display the result
    if (result) {
        std::cout << "It is possible to make a sum divisible by 20, 24, or equal to 2024 using coins." << std::endl;
    } else {
        std::cout << "It is not possible to make a sum divisible by 20, 24, or equal to 2024 using coins." << std::endl;
    }

    return 0;
}
