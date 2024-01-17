#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    void generatePermutations(vector<int>& arr, int index, set<vector<int>>& permutations) {
        if (index >= arr.size()) {
            permutations.insert(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);
            generatePermutations(arr, index + 1, permutations);
            swap(arr[index], arr[i]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>> permutationsSet;
        generatePermutations(arr, 0, permutationsSet);

        vector<vector<int>> uniquePermutations;
        for (const auto& permutation : permutationsSet) {
            uniquePermutations.push_back(permutation);
        }

        return uniquePermutations;
    }
};

int main() {
    Solution solution;

    // Example
    vector<int> input = {1, 2, 3};
    vector<vector<int>> result = solution.uniquePerms(input);

    // Print the result
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
