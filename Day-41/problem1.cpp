#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        stack<int> indexStack;
        indexStack.push(0);

        for (int i = 1; i < n; ++i) {
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int prevIndex = indexStack.top();
                indexStack.pop();
                result[prevIndex] = i - prevIndex;
            }
            indexStack.push(i);
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    vector<int> result = solution.dailyTemperatures(temperatures);

    // Print the result
    cout << "Daily Temperatures: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
