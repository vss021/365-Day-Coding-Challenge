#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        string a = s;
        if(a==""){
            return 1;
        }
        for(auto it:dictionary){
            if(it==a.substr(0,it.size())){
                a = a.substr(it.size());
                int ans = wordBreak(n,a,dictionary);
                if(ans==0){
                    a = s;
                }
                else{
                    return 1;
                }
            }
        }
        
        if(a==s){
            return 0;
        }
    }
    
};

int main() {
    Solution sol;
    vector<string> dictionary = {"apple", "pen"};
    string s = "applepenapple";
    int result = sol.wordBreak(s.size(), s, dictionary);
    if (result)
        cout << "String can be segmented.\n";
    else
        cout << "String cannot be segmented.\n";
    return 0;
}
