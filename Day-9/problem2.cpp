#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool makeEqual(vector<string>& words) {
    // Create an unordered map to store the count of each character in all words
    unordered_map<char, int> charCountMap;

    // Get the total number of words
    int n = words.size();

    // Iterate through each word in the vector
    for (int i = 0; i < n; i++) {
        string word = words[i];

        // Update the count of each character in the map
        for (char ch : word) {
            charCountMap[ch]++;
        }
    }

    // Check if the count of each character is divisible by the total number of words
    for (const auto& entry : charCountMap) {
        if (entry.second % n != 0) {
            // If not divisible, return false
            return false;
        }
    }

    // If all characters have counts divisible by n, return true
    return true;
}

int main() {
    // Example usage
    vector<string> words = {"abc", "aabc", "bc"};
    
    // Check if characters can be rearranged to make all words equal
    bool result = makeEqual(words);

    // Print the result
    cout << "Can be made equal: " << (result ? "true" : "false") << endl;

    return 0;
}
