#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char nthCharacter(string s, int r, int ind) {
        int n = s.length();
        
        while (r--) {
            string temp = "";
            for (int i = 0; i < n; i++) {
                if (s[i] == '0')
                    temp += "01";
                else
                    temp += "10";
            }
            s = temp.substr(0, n);
        }
        return s[ind];
    }
};

int main() {
    Solution solution;

    // Example input string, number of iterations, and index
    string s = "0";
    int r = 2;
    int ind = 3;

    // Call the nthCharacter method to get the character at the specified index after 'r' iterations
    char result = solution.nthCharacter(s, r, ind);

    // Output the result
    cout << "Character at index " << ind << " after " << r << " iterations: " << result << endl;

    return 0;
}
