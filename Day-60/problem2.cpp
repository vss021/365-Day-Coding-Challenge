#include <iostream>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;

class Solution{
public:
    int minValue(string s, int k) {
        // Count frequencies of characters in the string
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
            
        // Max heap to store frequencies
        priority_queue<int> pq;
        
        // Push frequencies into the max heap
        for (auto it : mp) {
            pq.push(it.second);
        }
        
        // Decrement the highest frequency characters until k becomes zero
        while (!pq.empty() && k--) {
            int top = pq.top();
            pq.pop();
            top--;
            if (top > 0) // Add the updated frequency back to the heap if it's still positive
                pq.push(top);
        }
        
        // Calculate the minimized sum of squares
        int sum = 0;
        while (!pq.empty()) {
            int freq = pq.top();
            sum += freq * freq;
            pq.pop();
        }
        
        return sum;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test_string = "abccc";
    int k = 1;
    cout << "Minimized value: " << solution.minValue(test_string, k) << endl;

    return 0;
}
