#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
    vector<vector<int>> ans;
    vector<int> top(K + 1, 0);  // Use K + 1 elements to simplify swapping

    unordered_map<int, int> frequencyMap;  // Rename mp to a more descriptive name

    for (int i = 0; i < N; i++) {
        frequencyMap[arr[i]]++;
        top[K] = arr[i];

        auto it = find(top.begin(), top.end() - 1, arr[i]);
        int ind = it - top.begin() - 1;

        // Bubble up the newly added element to maintain the sorted order
        for (int j = ind; j >= 0; --j) {
            if (frequencyMap[top[j]] < frequencyMap[top[j + 1]] ||
                (frequencyMap[top[j]] == frequencyMap[top[j + 1]] && top[j] > top[j + 1])) {
                swap(top[j], top[j + 1]);
            } else {
                break;
            }
        }

        // Create a vector with the top K elements for the current iteration
        vector<int> temp;
        for (int i = 0; i < K && top[i] != 0; ++i) {
            temp.push_back(top[i]);
        }

        // Add the vector to the result
        ans.push_back(temp);
    }

    return ans;
}


int main() {
    // Example input
    vector<int> arr = {3, 1, 2, 2, 4, 3, 4, 2, 4, 4};
    int N = arr.size();
    int K = 3;

    // Call the kTop function and print the result
    vector<vector<int>> result = kTop(arr, N, K);

    // Print the result
    cout << "Top " << K << " elements at each step:\n";
    for (const auto& vec : result) {
        for (int element : vec) {
            cout << element << " ";
        }
        cout << "\n";
    }

    return 0;
}
