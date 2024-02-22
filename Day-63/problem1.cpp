#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the judge
    int findJudge(int n, vector<vector<int>>& trust) {
        // If there are no trust relationships and there's only one person, that person is the judge
        if (trust.empty() && n == 1) {
            return 1;
        }

        // Initialize vectors to keep track of the in-degree and out-degree of each person
        vector<int> inDegree(n + 1, 0); // Number of people who trust this person
        vector<int> outDegree(n + 1, 0); // Number of people this person trusts

        // Iterate through the trust relationships and update the in-degree and out-degree vectors
        for (auto relationship : trust) {
            int personA = relationship[0];
            int personB = relationship[1];
            outDegree[personA]++; // Person A trusts someone
            inDegree[personB]++; // Someone trusts person B
        }

        // Iterate through the people and find the one who is trusted by everyone (in-degree is n - 1) and trusts no one (out-degree is 0)
        for (int person = 1; person <= n; person++) {
            if (inDegree[person] == n - 1 && outDegree[person] == 0) {
                return person; // This person is the judge
            }
        }

        // No judge found
        return -1;
    }
};

int main() {
    // Example usage
    Solution solution;
    int n = 4;
    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    cout << "Judge: " << solution.findJudge(n, trust) << endl; // Output should be 3
    return 0;
}
