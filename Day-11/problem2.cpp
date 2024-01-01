//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Create a frequency map to store remainders and their counts
        unordered_map<int, int> remainderCountMap;
    
        // Iterate through the nums array to populate the remainderCountMap
        for (int i = 0; i < nums.size(); i++) {
            int currentRemainder = nums[i] % k;
            int neededRemainder = (k - currentRemainder) % k;
    
            // Check if there is a needed remainder in the map
            if (remainderCountMap[neededRemainder]) {
                remainderCountMap[neededRemainder]--;
            } else {
                // If not, add the current remainder to the map
                remainderCountMap[currentRemainder]++;
            }
        }
    
        // Check if all remainders have been paired
        for (auto it = remainderCountMap.begin(); it != remainderCountMap.end(); it++) {
            if (it->second)
                return false;
        }
    
        // If all remainders are paired, return true
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends