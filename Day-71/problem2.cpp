#include <iostream>
using namespace std;

class Solution {
public:
    int peakElement(int arr[], int n) {
        if (n == 1)
            return 0;
        int low = 0;
        int high = n - 1;
        
        // Perform binary search to find a peak element.
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] >= arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution sol;
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = sol.peakElement(arr, n);
    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << arr[peakIndex] << endl;
    return 0;
}
