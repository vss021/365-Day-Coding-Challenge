#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:	

    void solve(vector<string>& ans, string option, int one, int zero, int n)
    {
        // base case
        if(n == 0 ){
            ans.push_back(option);
            return;
        }
        
        string op1 = option;
        op1.push_back('1');
        solve(ans, op1, one+1, zero, n-1);
        
        if(one > zero){
            string op2 = option;
            op2.push_back('0');
            solve(ans, op2, one, zero+1, n-1);
        }
    }

    vector<string> NBitBinary(int N)
    {
        vector<string> ans;
        int one = 0;
        int zero = 0;
        solve(ans, "", one, zero, N);
        return ans;
    }
};

int main() {
    int N = 3; // Example value of N

    Solution solution;
    vector<string> binaryNumbers = solution.NBitBinary(N);

    cout << "All " << N << "-bit binary numbers with more 1's than 0's:" << endl;
    for(const string& num : binaryNumbers) {
        cout << num << endl;
    }

    return 0;
}
