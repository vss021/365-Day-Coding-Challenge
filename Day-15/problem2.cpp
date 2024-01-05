#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Dynamic Programming
    
    - Use two variables, prev and prev0, to keep track of the number of ways to build and not build at each position.
    - Iterate from 2 to n and update prev and prev0 based on the current position.
    - Calculate the total number of ways for the left side (res) as the sum of prev and prev0.
    - Return the square of res as the total possibilities for both sides.
*/

int TotalWays(int n)
{
    // Initialize variables to keep track of ways to build and not build
    long prev = 1, prev0 = 1;

    // Iterate from 2 to n
    for (int i = 2; i <= n; ++i)
    {
        // Calculate the ways to build and not build at the current position
        long cur = prev0;
        long cur0 = (prev + prev0) % mod;

        // Update values for the next position
        prev = cur;
        prev0 = cur0;
    }

    // Calculate the total number of ways for the left side
    long res = (prev + prev0) % mod;

    // Return the total possibilities (square of res) as the result
    return static_cast<int>((res * res) % mod);
}


int main()
{
    // Example usage of the TotalWays function
    int n = 5; // You can change this value as needed

    // Call the TotalWays function
    int result = TotalWays(n);

    // Output the result
    cout << "Total ways for N = " << n << ": " << result << std::endl;

    return 0;
}
