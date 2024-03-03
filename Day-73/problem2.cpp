#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(string first, string second) {
        return first + second > second + first;
    }

    string printLargest(int n, vector<string>& arr) {
        sort(arr.begin(), arr.end(), cmp);

        string result = "";

        for (auto x : arr) {
            result += x;
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"54", "546", "548", "60"};
    int n = arr.size();
    
    cout << "Largest arrangement: " << solution.printLargest(n, arr) << endl;

    return 0;
}
