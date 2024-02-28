#include <iostream>

using namespace std;

int* game_with_number(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        arr[i] |= arr[i + 1];

    return arr;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int* result = game_with_number(arr, n);

    cout << "Array after operation: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    // Deallocate memory if necessary
    // delete[] result;

    return 0;
}
