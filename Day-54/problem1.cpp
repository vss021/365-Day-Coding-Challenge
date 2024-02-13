#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            if (isPalindrome(word))
                return word;
        }
        return "";
    }
};

int main() {
    Solution solution;
    vector<string> words = {"level", "algorithm", "madam", "hello", "racecar"};
    string first_palindrome = solution.firstPalindrome(words);
    if (first_palindrome.empty())
        cout << "No palindrome found." << endl;
    else
        cout << "First palindrome: " << first_palindrome << endl;
    return 0;
}
