#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to sort characters in a string based on their frequency
    string frequencySort(string s) {
        // Comparator function for priority_queue
        auto compare = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second; // Sort by frequency
        };

        // Priority queue to store characters and their frequencies
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);
        
        // Map to store characters and their frequencies
        unordered_map<char, int> frequencyMap;
        
        // Count frequency of each character
        for (char c : s) {
            frequencyMap[c]++;
        }
        
        // Push characters and their frequencies into priority queue
        for (const auto& entry : frequencyMap) {
            pq.push(make_pair(entry.first, entry.second));
        }
        
        // Build the result string by appending characters based on their frequencies
        string result = "";
        while (!pq.empty()) {
            pair<char, int> currentPair = pq.top();
            pq.pop();
            result.append(currentPair.second, currentPair.first); // Append character 'second' times
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string inputString = "tree";
    cout << "Original string: " << inputString << endl;
    string sortedString = solution.frequencySort(inputString);
    cout << "Sorted string by character frequency: " << sortedString << endl;
    return 0;
}
