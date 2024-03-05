#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution class  here...


class Solution {
public:
    // Time Complexity (TC): O(1) - Constant time complexity because the board size is fixed (9x9)
    // Space Complexity (SC): O(1) - Constant space complexity due to the fixed-size unordered_set
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows, columns, and sub-boxes for validity
        for (int i = 0; i < 9; ++i) {
            if (!isValidRow(board, i) || !isValidColumn(board, i) || !isValidSubBox(board, i))
                return false;
        }
        return true;
    }
private:
    // Check if a row is valid
    bool isValidRow(const vector<vector<char>>& board, int row) {
        unordered_set<char> seen;
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] != '.') {
                if (seen.find(board[row][j]) != seen.end())
                    return false; // Duplicate found
                seen.insert(board[row][j]);
            }
        }
        return true;
    }
    // Check if a column is valid
    bool isValidColumn(const vector<vector<char>>& board, int col) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] != '.') {
                if (seen.find(board[i][col]) != seen.end())
                    return false; // Duplicate found
                seen.insert(board[i][col]);
            }
        }
        return true;
    }
    // Check if a 3x3 sub-box is valid
    bool isValidSubBox(const vector<vector<char>>& board, int box) {
        unordered_set<char> seen;
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] != '.') {
                    if (seen.find(board[i][j]) != seen.end())
                        return false; // Duplicate found
                    seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    // Example Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Check if the Sudoku board is valid
    if (sol.isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}
