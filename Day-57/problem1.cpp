#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to store frequency of each number
        map<int, int> numFrequency;
        
        // Count frequency of each number
        for (int num : arr)
            numFrequency[num]++;

        // Priority queue to store frequencies in ascending order
        priority_queue<int, vector<int>, greater<int>> frequencyQueue;
        
        // Push frequencies into the priority queue
        for (auto& pair : numFrequency)
            frequencyQueue.push(pair.second);
        
        // Remove elements with lowest frequency until k becomes zero
        while (k > 0) {
            k -= frequencyQueue.top(); // Reduce k by the lowest frequency
            if (k >= 0)
                frequencyQueue.pop(); // Pop the lowest frequency element if k is non-negative
        }
        
        // Return the number of unique integers left
        return frequencyQueue.size();
    }
};


int main() {
    Solution solution;
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    int result = solution.findLeastNumOfUniqueInts(arr, k);
    cout << "Least number of unique integers after removing " << k << " elements: " << result << endl;
    return 0;
}
