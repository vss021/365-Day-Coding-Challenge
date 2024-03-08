#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool sameFreq(string s) {
        // Array to store frequency of characters ('a' to 'z')
        int freq[26] = {0};
        // Variables to store size, minimum frequency, and minimum count
        int size = 0, minFreq = INT_MAX;

        // Count frequency of each character in the string
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Calculate size and minimum frequency
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                size += freq[i];
                minFreq = min(minFreq, freq[i]);
            }
        }

        // Calculate minimum count
        int minCount = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == minFreq) {
                minCount += minFreq;
            }
        }

        int c = 0, flag = 0;
        
        // Check conditions for same frequency
        if (size == minCount || size - 1 == minCount + minFreq)
            return true;
        else if (minFreq == 1) {
            // If minimum frequency is 1, check if all other frequencies are the same
            for (int i = 0; i < 26; i++) {
                if (freq[i] != 1 && freq[i] != 0) {
                    if (flag == 0) {
                        c = freq[i];
                        flag = 1;
                    } else {
                        if (freq[i] != c)
                            return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
};

// Test cases
int main() {
    Solution solution;
    
    vector<string> testCases = {"abbccc", "aabbccc", "aaabbccc", "aabbcccd"};
    for (const auto& s : testCases) {
        cout << "For string '" << s << "': " << (solution.sameFreq(s) ? "Same frequency" : "Not same frequency") << endl;
    }

    return 0;
}
