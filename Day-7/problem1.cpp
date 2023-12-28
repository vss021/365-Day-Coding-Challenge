#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int dp[1000][1000];
    
    bool helper(string &wild, string &pattern, int wcurr, int pcurr){
        if(pcurr==pattern.size()){
            for(int i=wcurr;i<wild.size();i++){
                if(wild[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(wcurr==wild.size()){
            return false;
        }
        
        if(dp[wcurr][pcurr]!=-1){
          return dp[wcurr][pcurr];
        }
        if(wild[wcurr]==pattern[pcurr] || wild[wcurr]=='?'){
            return dp[wcurr][pcurr]=helper(wild,pattern,wcurr+1,pcurr+1);
        }
        
        if(wild[wcurr]=='*'){
            return dp[wcurr][pcurr]=helper(wild,pattern,wcurr,pcurr+1) || helper(wild,pattern,wcurr+1,pcurr);
        }
        
        return dp[wcurr][pcurr]=false;
    }
    
    bool match(string wild, string pattern){
        memset(dp,-1,sizeof(dp));
        return helper(wild,pattern,0,0);
    }
};

int main() {
    Solution solution;

    // Test cases
    string wild1 = "ab*cd";
    string pattern1 = "abaccd";
    printf("Pattern 1 matches Wildcard 1: %d\n", solution.match(wild1, pattern1));

    string wild2 = "a*c?d";
    string pattern2 = "abcdd";
    printf("Pattern 2 matches Wildcard 2: %d\n", solution.match(wild2, pattern2));

    string wild3 = "abc";
    string pattern3 = "a*";
    printf("Pattern 3 matches Wildcard 3: %d\n", solution.match(wild3, pattern3));

    return 0;
}
