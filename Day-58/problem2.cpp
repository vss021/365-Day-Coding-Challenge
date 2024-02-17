#include <iostream>
using namespace std;

class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            if (2 * i + 1 < n && arr[i] < arr[2 * i + 1]) {
                return false;
            }
            if (2 * i + 2 < n && arr[i] < arr[2 * i + 2]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int arr1[] = {10, 9, 8, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    if (solution.isMaxHeap(arr1, n1)) {
        cout << "arr1 is a max heap" << endl;
    } else {
        cout << "arr1 is not a max heap" << endl;
    }

    int arr2[] = {10, 9, 8, 7, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    if (solution.isMaxHeap(arr2, n2)) {
        cout << "arr2 is a max heap" << endl;
    } else {
        cout << "arr2 is not a max heap" << endl;
    }

    return 0;
}
