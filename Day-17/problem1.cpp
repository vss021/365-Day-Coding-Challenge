#include <iostream>
#include <algorithm>
using namespace std;

/*
problem : 
Given an array arr[] of N elements and a number K., split the given array 
into K subarrays such that the maximum subarray sum achievable out of K subarrays 
formed is minimum possible. Find that possible subarray sum.
*/

/*
Wonder why Binary Search? 
- the key insight is that this minimum possible maximum subarray sum forms a monotonic range.
 In this particular problem, as we iterate through the binary search, we are essentially 
 checking whether a given maximum subarray sum is feasible or not.

If a certain maximum subarray sum is feasible, then all smaller maximum subarray sums
 are also feasible. Conversely, if a certain maximum subarray sum is not feasible, then all 
 larger maximum subarray sums are also not feasible.
*/
bool canSplit(int arr[], int N, int K, int mid) {
    int subarraySum = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > mid) {
            // Cannot split if an element is greater than mid
            return false;
        }

        subarraySum += arr[i];

        if (subarraySum > mid) {
            // Need to start a new subarray
            K--;
            subarraySum = arr[i];
        }
    }

    // Check if it's possible to split into K subarrays
    return (K >= 1);
}

int splitArray(int arr[], int N, int K) {
    int totalSum = 0;
    for (int i = 0; i < N; i++) {
        totalSum += arr[i];
    }

    int low = 0, high = totalSum;
    int result = totalSum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(arr, N, K, mid)) {
            // Update the result and search in the lower half
            result = mid;
            high = mid - 1;
        } else {
            // Search in the upper half
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    int result = splitArray(arr, N, K);

    cout << "Minimum sum to split into " << K << " subarrays: " << result << endl;

    return 0;
}
