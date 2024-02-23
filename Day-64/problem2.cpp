#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        
        // Calculate maximum profit from left to right
        vector<int> leftToRightProfit(n);
        int leftMinPrice = price[0];
        for (int i = 1; i < n; i++) {
            leftMinPrice = min(leftMinPrice, price[i]);
            leftToRightProfit[i] = max(leftToRightProfit[i - 1], price[i] - leftMinPrice);
        }
        
        // Calculate maximum profit from right to left
        vector<int> rightToLeftProfit(n);
        int rightMaxPrice = price[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMaxPrice = max(rightMaxPrice, price[i]);
            rightToLeftProfit[i] = max(rightToLeftProfit[i + 1], rightMaxPrice - price[i]);
        }
        
        // Calculate maximum combined profit
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftToRightProfit[i] + rightToLeftProfit[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
