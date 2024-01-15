#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Map to store the count of losses for each player
        unordered_map<int, int> lost_map;

        // Count the losses for each player
        for (int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        // Vectors to store players who have not lost and players who lost only once
        vector<int> notLost;
        vector<int> onceLost;

        // Check each match to determine winners and once-lost players
        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            // If the winner has not lost before, add them to the notLost vector
            if (lost_map.find(winner) == lost_map.end()) {
                notLost.push_back(winner);
                lost_map[winner] = 2;  // Assume they won twice (not actually counted)
            }

            // If the loser lost only once, add them to the onceLost vector
            if (lost_map[loser] == 1) {
                onceLost.push_back(loser);
            }
        }

        // Sort the vectors in ascending order
        sort(notLost.begin(), notLost.end());
        sort(onceLost.begin(), onceLost.end());

        // Return the result as a vector of vectors
        return {notLost, onceLost};
    }
};

int main() {
    // Example matches data
    vector<vector<int>> matches = {
        {1, 2},
        {3, 4},
        {2, 3},
        {5, 1},
        {6, 2}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the findWinners function with the example matches
    vector<vector<int>> result = solution.findWinners(matches);

    // Display the result
    cout << "Players who have not lost: ";
    for (int player : result[0]) {
        cout << player << " ";
    }
    cout << endl;

    cout << "Players who lost only once: ";
    for (int player : result[1]) {
        cout << player << " ";
    }
    cout << endl;

    return 0;
}
