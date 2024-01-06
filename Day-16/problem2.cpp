#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:

    /*
    Note: 
    We only need to calculate the number of prime factors, so there's no need to 
    store respective numbers with their powers.

    Approach:

    1. Iterate from 'a' to 'b' inclusive.

    2. Get the prime factor count for each number.

    3. Add the prime factor count of each number to the sum.

    Time Complexity: O((b - a) * log(b)). Space Complexity: O(1).
    */

    // Function to calculate the count of prime factors of a number
    int getPrimeFactorCount(int n) {
        int count = 0;

        // Handle powers of 2
        while (n % 2 == 0) {
            count++;
            n /= 2;
        }

        // Check odd factors starting from 3
        for (int i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                count++;
                n /= i;
            }
        }

        // If there is a remaining prime factor greater than 2
        if (n > 2) {
            count++;
        }

        return count;
    }

    // Function to calculate the sum of prime factor counts for numbers in the range [a, b]
    int sumOfPowers(int a, int b) {
        int sum = 0;

        // Iterate from 'a' to 'b' inclusive
        for (int i = a; i <= b; i++) {
            // Add the prime factor count of each number to the sum
            sum += getPrimeFactorCount(i);
        }

        return sum;
    }
};

int main() {
    Solution solution;

    // Example usage
    int a = 10;
    int b = 15;

    int result = solution.sumOfPowers(a, b);
    cout << "Sum of Prime Factor Counts: " << result << endl;

    return 0;
}
