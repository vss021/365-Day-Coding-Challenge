#include <iostream>
#include <unordered_map>
using namespace std;

/*
Approach:
1. Count the occurrences of each element in the array using a map.
2. Traverse the map and count the elements whose frequency is greater than n/k.
3. Return the count.

Time complexity: O(n), where n is the size of the array.
Space complexity: O(k), where k is the number of distinct elements in the array.
*/

int countOccurrencesAboveThreshold(int arr[], int n, int k) {
    // Step 1: Count occurrences of each element
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }

    // Step 2: Count elements with frequency greater than n/k
    int count = 0;
    for (auto elementFrequency : frequencyMap) {
        if (elementFrequency.second > n / k) {
            count++;
        }
    }

    // Step 3: Return the count
    return count;
}

int main() {
    // Example usage
    int arr[] = {4, 4, 2, 2, 2, 3, 3, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = countOccurrencesAboveThreshold(arr, n, k);

    cout << "Number of elements with frequency greater than n/k: " << result << endl;

    return 0;
}
