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
            ans.push_back(op);
            return;
        }

        // Exclude the current character
        solve(str, op, ans, ind + 1);

        // Include the current character
        string op1 = op;
        op1.push_back(str[ind]);
        solve(str, op1, ans, ind + 1);
    }

    // Function to generate all possible strings from a given string
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        
        // Call the recursive function to generate all possible strings
        solve(s, "", ans, 0);
        
        // Sort the result vector
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.AllPossibleStrings("abc");

    // Output the generated strings
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
