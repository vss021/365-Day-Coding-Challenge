#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    vector<int> bruteForce(string& pattern, string& text) {
        // Time complexity - O(N*M)
        // Space complexity- O(1)
            vector<int> occurrences;
            int textLength = text.size();
            int patternLength = pattern.size();

            for (int i = 0; i < (textLength - patternLength + 1); ++i) {
                bool isMatch = true;
                int patternIndex = 0;

                for (int j = i; j < (i + patternLength); ++j) {
                    if (text[j] == pattern[patternIndex]) {
                        ++patternIndex;
                    } else {
                        isMatch = false;
                        break;
                    }
                }

                if (isMatch) {
                    occurrences.push_back(i + 1);
                }
            }

            return occurrences;
        }
        
        
        vector<int> KMP_Approach(string& pattern, string& text) {
             // LPS array
             
             // Time complexity - O(M+N)
            // Space complexity- O(N)
            vector<int> lps(pattern.size(), 0);
            int i = 0;
            int j = 1;
        
            while (j < pattern.size()) {
                while (i > 0 && pattern[i] != pattern[j]) {
                    i--;
                }
        
                if (pattern[i] == pattern[j]) {
                    lps[j] = i + 1;
                    i++;
                } else {
                    lps[j] = 0;
                }
        
                j++;
            }
        
            // Matching pattern
            j = 0;
            i = 0;
            vector<int> occurrences;
        
            while (i < text.size()) {
                if (text[i] == pattern[j]) {
                    i++;
                    j++;
                }
        
                if (j == pattern.size()) {
                    occurrences.push_back(i - j + 1);
                    j = lps[j - 1];
                } else if (i < text.size() && text[i] != pattern[j]) {
                    if (j == 0) {
                        i++;
                    } else {
                        j = lps[j - 1];
                    }
                }
            }
        
            return occurrences;
        }
        
        
        vector <int> search(string pat, string txt)
        {
            //code here
            
            // return bruteForce(pat, txt);
            return KMP_Approach(pat, txt);
            
        }
};

int main() {
    Solution solution;

    // Test with brute force approach
    string pattern1 = "abc";
    string text1 = "abcdabc";
    vector<int> result1 = solution.bruteForce(pattern1, text1);

    cout << "Brute Force Approach Results: ";

    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    // Test with KMP approach
    string pattern2 = "abc";
    string text2 = "abcdabc";
    vector<int> result2 = solution.KMP_Approach(pattern2, text2);

    cout << "KMP Approach Results: ";
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
