#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &x : nums) {
            mp[x]++;
        }

        for(auto x : mp) {
            if(x.second > 1) {
                return x.first;
            }
        }

        return -1;
    }
};

int main() {
    // Example usage for findDuplicate function
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution solution;
    int repeatedNum = solution.findDuplicate(nums);

    if(repeatedNum != -1) {
        cout << "The repeated number is: " << repeatedNum << endl;
    } else {
        cout << "No repeated number found!" << endl;
    }

    return 0;
}
