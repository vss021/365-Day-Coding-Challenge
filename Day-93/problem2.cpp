#include <iostream>
#include <vector>

using namespace std;

vector<int> Series(int n) {
    int mod = 1e9 + 7;
    vector<int> v(n + 1, 0);
    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= n; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % mod;
    }

    return v;
}

int main() {
    // Example usage for Series function
    int n = 10; // Generate Fibonacci series till the 10th term (0-based indexing)

    vector<int> fibSeries = Series(n);

    cout << "Fibonacci Series modulo 10^9 + 7:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << fibSeries[i] << " ";
    }
    cout << endl;

    return 0;
}
