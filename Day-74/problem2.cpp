#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int i = 0;
        int j = tokens.size() - 1;

        while (i < j) {
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i++];
            } else if (score >= 1 && power + tokens[j] >= tokens[i]) {
                power += tokens[j--];
                score--;
            } else {
                break;
            }
        }

        while (i < j + 1 && power >= tokens[i]) {
            power -= tokens[i++];
            score++;
        }

        return score;
    }
};

int main() {
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    Solution solver;
    int maxScore = solver.bagOfTokensScore(tokens, power);

    cout << "Maximum score: " << maxScore << endl;

    return 0;
}
