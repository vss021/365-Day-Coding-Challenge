#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    cout << "First unique character in '" << s1 << "': " << solution.firstUniqChar(s1) << endl;
    cout << "First unique character in '" << s2 << "': " << solution.firstUniqChar(s2) << endl;
    cout << "First unique character in '" << s3 << "': " << solution.firstUniqChar(s3) << endl;

    return 0;
}
