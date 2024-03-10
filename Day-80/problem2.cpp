#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string str) {
        string output = "";
        map<char, int> mp;

        for (auto i : str) {
            mp[i]++;
            if (mp[i] == 1) {
                output += i;
            }
        }

        return output;
    }
};

int main() {
    Solution sol;
    string input = "leetcode";

    cout << "Original string: " << input << endl;

    string result = sol.removeDuplicates(input);

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}
