#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Recursive function to generate all possible strings
    void solve(string str, string op, vector<string> &ans, int ind) {
        // Base case: If the index exceeds the length of the string, add the generated string to the result vector
        if (ind >= str.size()) {
            if (op.size() > 0) // Check if op is not empty before adding it to ans
                ans.push_back(op);
            return;
        }

        // Exclude the current character
        solve(str, op, ans, ind + 1);

        // Include the current character
        string op1 = op + str[ind]; // Concatenate the current character to the string
        solve(str, op1, ans, ind + 1);
    }

    // Function to generate all possible strings from a given string
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        string op = ""; // Initialize op here
        int ind = 0;

        // Call the recursive function to generate all possible strings
        solve(s, op, ans, ind);

        // Sort the result vector
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.AllPossibleStrings("abc");

    // Output the generated strings
    cout << "All possible subsequences of 'abc' in lexicographically-sorted order:" << endl;
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
