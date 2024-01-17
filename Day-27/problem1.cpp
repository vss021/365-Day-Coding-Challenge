#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (auto x : arr) {
            freq[x]++;
        }
        unordered_set<int> s;
        for (auto x : freq) {
            s.insert(x.second);
        }
        return freq.size() == s.size();
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Example 1: " << (solution.uniqueOccurrences(arr1) ? "true" : "false") << endl;

    // Example 2
    vector<int> arr2 = {1, 2};
    cout << "Example 2: " << (solution.uniqueOccurrences(arr2) ? "true" : "false") << endl;

    // Example 3
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << "Example 3: " << (solution.uniqueOccurrences(arr3) ? "true" : "false") << endl;

    return 0;
}
