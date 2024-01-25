#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    // Sieve of Eratosthenes to mark prime numbers up to 9999
    void SieveOfEratosthenes(int n, vector<bool> &prime) {
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    // Function to find the minimum number of steps to convert Num1 to Num2
    int minStepsToConvert(int Num1, int Num2) {
        // Vector to mark prime numbers up to 9999
        vector<bool> prime(10000, true);

        // Mark non-prime numbers using Sieve of Eratosthenes
        SieveOfEratosthenes(9999, prime);

        int steps = 0;
        queue<int> q;
        q.push(Num1);

        while (!q.empty()) {
            int sz = q.size();

            // Explore all numbers at the current level
            for (int i = 0; i < sz; i++) {
                int val = q.front();
                q.pop();

                // If the current number is equal to the target, return the number of steps
                if (val == Num2)
                    return steps;

                string s = to_string(val);

                // Iterate over all digits in the number
                for (int j = 0; j < 4; j++) {
                    char c = s[j];

                    // Try changing the current digit to all possible digits (0-9)
                    for (int k = 0; k < 10; k++) {
                        // Skip leading zeros
                        if (k == 0 && j == 0)
                            continue;

                        s[j] = '0' + k;
                        int temp = stoi(s);

                        // If the modified number is prime, add it to the queue and mark it as visited
                        if (prime[temp]) {
                            q.push(temp);
                            prime[temp] = false;
                        }
                    }

                    // Restore the original digit
                    s[j] = c;
                }
            }

            // Move to the next level of numbers
            steps++;
        }

        // If no solution is found, return -1
        return -1;
    }
};

int main() {
    Solution solution;

    int Num1 = 1033;
    int Num2 = 8179;

    int result = solution.minStepsToConvert(Num1, Num2);

    cout << "Minimum steps to convert " << Num1 << " to " << Num2 << ": " << result << endl;

    return 0;
}
