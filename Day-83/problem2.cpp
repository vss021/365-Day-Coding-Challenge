#include <iostream>
#include <vector>

using namespace std;

vector<int> diagonalPattern(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> pattern;

    // Upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            pattern.push_back(matrix[j][i - j]);
        }
    }

    // Lower triangle
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            pattern.push_back(matrix[i + j][n - 1 - j]);
        }
    }

    return pattern;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = diagonalPattern(matrix);
    cout << "Diagonal Pattern:";
    for (int num : result) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
