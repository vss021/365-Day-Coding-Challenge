#include <vector>
#include <iostream>

using namespace std;

vector<int> rockPaperScissor(int k, string nezuko, string zenitsu) {
    int n_nezuko = nezuko.size();
    int n_zenitsu = zenitsu.size();
    int nezuko_wins = 0, zenitsu_wins = 0;

    for (int i = 0; i < k; ++i) {
        char nezuko_move = nezuko[i % n_nezuko];
        char zenitsu_move = zenitsu[i % n_zenitsu];

        if (nezuko_move == zenitsu_move) {
            // Draw, do nothing
        } else if ((nezuko_move == 'R' && zenitsu_move == 'S') ||
                   (nezuko_move == 'S' && zenitsu_move == 'P') ||
                   (nezuko_move == 'P' && zenitsu_move == 'R')) {
            // Nezuko wins
            nezuko_wins++;
        } else {
            // Zenitsu wins
            zenitsu_wins++;
        }
    }

    return {nezuko_wins, zenitsu_wins};
}

int main() {
    int k = 5;  // Number of games
    string nezuko_moves = "RPSRP";  // Nezuko's moves
    string zenitsu_moves = "SPSRS";  // Zenitsu's moves

    vector<int> result = rockPaperScissor(k, nezuko_moves, zenitsu_moves);

    cout << "Nezuko wins: " << result[0] << endl;
    cout << "Zenitsu wins: " << result[1] << endl;

    return 0;
}
