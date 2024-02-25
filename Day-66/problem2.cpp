#include <iostream>
using namespace std;

// Original solution
long long int count(long long int n) {
    long long int ans = 0;
    for(int i = 0; i <= n; i += 3) {
        ans += (n - i) % 5 ? 0 : (n - i) / 10 + 1;
    }
    return ans;
}

// Another solution
long long int countAlternative(long long int n) {
    long long int ans = 0;
    for (int i = 0; i <= n; i += 3) {
        if ((n - i) % 5 == 0) {
            ans += (n - i) / 10 + 1;
        }
    }
    return ans;
}

int main() {
    // Main comment explaining the purpose of the function
    // Count the number of integers divisible by 3 within the range [0, n]
    long long int n = 100; // Example input
    cout << "Using original solution: " << count(n) << endl;
    cout << "Using alternative solution: " << countAlternative(n) << endl;
    return 0;
}
