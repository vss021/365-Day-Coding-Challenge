#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Tc => N*NlogN
        //  sp => N*N
        // string in sorting order, string strs  
        unordered_map<string, vector<string>> mp;

        for(string s : strs)
        {

            string temp = s;

            sort(temp.begin(), temp.end());
            // for push same index vector 
            mp[temp].push_back(s);
        }

        vector<vector<string>> result;

        for(auto str : mp)
        {
            result.push_back(str.second);
        }

        return result;
        
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : groupedAnagrams) {
        cout << "[";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}
