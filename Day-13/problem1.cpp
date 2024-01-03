#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (auto& row : bank) {
            
            int curRowCount = countOnes(row);
            if (curRowCount == 0) {
                continue;
            }

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }

private:
    int countOnes(const string& s) {
        int count = 0;
        for (char c : s) {
            count += c - '0';
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Example usage with a vector of strings
    vector<string> bank = {"1001", "0100", "0010", "0001"};

    int result = solution.numberOfBeams(bank);

    cout << "Total number of laser beams: " << result << endl;

    return 0;
}
