#include <iostream>

using namespace std;

class Solution {
public:
    void swapElements(int arr[], int n) {
        int j = 0;
        for (int i = 2; i < n; i = j + 2) {
            swap(arr[j++], arr[i]);
        }
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution solver;
    solver.swapElements(arr, n);

    cout << "Array after swapping elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
