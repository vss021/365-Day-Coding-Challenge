#include <iostream>
using namespace std;

class Solution {
public:
    // Solution 1: Brute Force Approach
    // TC = O(N^2)
    int BruteForceApproach(int arr[], int N) {
        int result = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(arr[j] >= arr[i]) {
                    result = max(j - i, result);
                }
            }
        }
        
        return result;
    }
    
    // Solution 2: Optimized Approach
    // TC = O(N)
    // SP = O(N)
    int optimizedApproach(int arr[], int N) {
        int garr[N], sarr[N], result = -1;
        
        garr[N - 1] = arr[N - 1];
        sarr[0] = arr[0];
        
        for(int i = 1, j = N - 2; i < N, j >= 0; i++, j--) {
            sarr[i] = min(sarr[i - 1], arr[i]);
            garr[j] = max(garr[j + 1], arr[j]);
        }
        
        int i = 0, j = 0;
        
        while(i < N && j < N) {
            if(sarr[i] <= garr[j]) {
                result = max(result, j - i);
                j++;
            } else {
                i++;
            }
        }
        
        return result;
    }
    
    // Solution 3: Most Optimized Approach
    // TC = O(N)
    // SP = O(1)
    int mostOptimizedApproach(int a[], int n) {
        int ans = 0;
        int i = 0;
        int j = n - 1;
        
        while(i < n) {
            if(a[i] > a[j]) {
                j--;
            } else {
                ans = max(ans, j - i);
                j = n - 1;
                i++;
            }
        }
        
        return ans;
    }
    
    // Main function for testing
    int maxIndexDiff(int a[], int n) {
        return mostOptimizedApproach(a, n);
    }
};

int main() {
    Solution sol;

    // Example usage
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxDiff = sol.maxIndexDiff(arr, n);
    cout << "Maximum index difference: " << maxDiff << endl;

    return 0;
}
