#include <iostream>
#include <climits>

using namespace std;

long long int maxSubArraySum(long long int a[], int size) {
    long long int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        // Reset to 0 if the current subarray sum becomes negative
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve() {
    int n, m;
    cin >> n;

    // Input array A (left)
    long long int arrAL[n], arrAF[n + 1], minofA = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arrAL[i];
        arrAF[i + 1] = arrAL[i];

        // Find the minimum element in array A
        minofA = max(minofA, arrAL[i]);
    }

    cin >> m;

    // Input array B
    long long int arrB[m], maxi = 0;
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];

        // Calculate the sum of positive elements in array B
        if (arrB[i] > 0) {
            maxi += arrB[i];
        }

        // Update the minimum element in array A
        if (arrB[i] > minofA) {
            minofA = arrAL[i];
        }
    }

    // If the minimum element in A is non-positive, the result is the minimum element
    if (minofA <= 0) {
        cout << minofA << endl;
    } else {
        // Add the sum of positive elements in B to the end and beginning of array A
        arrAL[n] = maxi;
        arrAF[0] = maxi;

        // Calculate the maximum subarray sum considering both array A (left) and array A (right)
        long long int maxi2 = max(maxSubArraySum(arrAL, n + 1), maxSubArraySum(arrAF, n + 1));

        cout << maxi2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
