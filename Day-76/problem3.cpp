#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Naive string searching algorithm
    // Time Complexity: O((n-m+1)*m), where n is the length of the text and m is the length of the pattern.
    //                  In the worst case, the algorithm may compare every character of the text with every character of the pattern.
    // Space Complexity: O(1)
    vector<int> naiveSearch(string pattern, string text) {
        int n = text.size();
        int m = pattern.size();
        vector<int> result;

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                result.push_back(i);
            }
        }

        return result;
    }

    // Knuth-Morris-Pratt string searching algorithm
    // Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.
    // Space Complexity: O(m)
    vector<int> kmpSearch(string pattern, string text) {
        int n = pattern.size();
        int m = text.size();
        vector<int> result;

        if (n > m) {
            return {};
        }

        vector<int> lps = computeLPS(pattern);

        int i = 0, j = 0;
        while (i < m) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            if (j == n) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < m && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    // Rabin-Karp string searching algorithm
    // Time Complexity: O((n-m+1)*m), where n is the length of the text and m is the length of the pattern.
    //                  In the worst case, the algorithm may compute the hash value for every possible substring of the text.
    // Space Complexity: O(1)
    vector<int> rabinKarpSearch(string pattern, string text) {
        int q = 101; // A prime number
        int d = 256; // Number of characters in the input alphabet

        int n = text.length();
        int m = pattern.length();
        int p = 0; // Hash value for pattern
        int t = 0; // Hash value for text
        int h = 1;

        vector<int> result;

        // Calculate hash value for pattern and the first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }

        // Calculate h = d^(m-1)
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // Check the hash values of current window of text and pattern
            // If the hash values match, then only check for characters one by one
            if (p == t) {
                // Check for characters one by one
                int j;
                for (j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        break;
                    }
                }

                if (j == m) {
                    result.push_back(i);
                }
            }

            // Calculate hash value for next window of text: Remove leading digit,
            // add trailing digit
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;

                // We might get negative value of t, converting it to positive
                if (t < 0) {
                    t = (t + q);
                }
            }
        }

        return result;
    }

private:
    // Helper function for KMP to compute the LPS array
    vector<int> computeLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution solution;

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> naiveResult = solution.naiveSearch(pattern, text);
    vector<int> kmpResult = solution.kmpSearch(pattern, text);
    vector<int> rabinKarpResult = solution.rabinKarpSearch(pattern, text);

    // Print results
    cout << "Naive Search: ";
    for (int i : naiveResult) {
        cout << i << " ";
    }
    cout << endl;

    cout << "KMP Search: ";
    for (int i : kmpResult) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Rabin-Karp Search: ";
    for (int i : rabinKarpResult) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
