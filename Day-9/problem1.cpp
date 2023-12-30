#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> findWinner(const string arr[], int n) {
    // Create an unordered map to store the count of each string
    unordered_map<string, int> stringCountMap;

    // Populate the map with the count of each string in the array
    for (int i = 0; i < n; i++) {
        stringCountMap[arr[i]]++;
    }

    // Variables to keep track of the maximum count and the lexicographically smallest string
    int maxCount = INT_MIN;
    string winner = "";

    // Iterate through the map to find the winner
    for (const auto& entry : stringCountMap) {
        // If the current count is greater than the maximum count, update the winner
        if (entry.second > maxCount) {
            maxCount = entry.second;
            winner = entry.first;
        }
        // If the current count is equal to the maximum count, update the winner for lexicographically smaller string
        else if (entry.second == maxCount && entry.first < winner) {
            winner = entry.first;
        }
    }

    // Return the winner and its count as a vector of strings
    return {winner, to_string(maxCount)};
}

int main() {
    // Example usage
    string strings[] = {"apple", "banana", "orange", "grape", "kiwi", "banana", "kiwi", "apple"};
    int size = sizeof(strings) / sizeof(strings[0]);

    vector<string> result = findWinner(strings, size);

    // Print the result
    cout << "Winner: " << result[0] << ", Count: " << result[1] << endl;

    return 0;
}
