#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int kadane(const vector<int>& arr) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int num : arr) {
        // Kadane's algorithm to find the maximum subarray sum
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

void solve() {
    // Input for array 'a'
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Input for array 'b'
    int m;
    cin >> m;
    vector<int> b(m);
    int positiveSumB = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] > 0) {
            positiveSumB += b[i];
        }
    }

    // Calculate the maximum subarray sum starting from the beginning
    int maxStartSum = kadane(a);

    // Reverse array 'a' to calculate the maximum subarray sum starting from the end
    reverse(a.begin(), a.end());
    int maxEndSum = kadane(a);

    // Determine the final answer
    int finalResult = max(maxStartSum, maxEndSum) + positiveSumB;

    cout << finalResult << endl;
}

int main() {
    // Example usage
    solve();

    return 0;
}
