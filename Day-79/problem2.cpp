#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res; // Vector to store all possible board configurations
    
    // Function to check if it's safe to place a queen at the given position
    bool is_Safe(vector<string>& board, int row, int column) {
        // Check for queens in the same column
        for (int index = row; index >= 0; index--)
            if (board[index][column] == 'Q')
                return false;
        
        // Check for queens in the left diagonal
        for (int index = row, jindex = column; index >= 0 && jindex >= 0; index--, jindex--)
            if (board[index][jindex] == 'Q')
                return false;
        
        // Check for queens in the right diagonal
        for (int index = row, jindex = column; index >= 0 && jindex < board.size(); index--, jindex++)
            if (board[index][jindex] == 'Q')
                return false;
        
        return true;
    }
    
    // Function to recursively place queens on the board and find all configurations
    void placequeen(vector<string>& board, int row) {
        // If all queens are placed successfully, add the current board configuration to the result
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        
        // Iterate over each column in the current row
        for (int index = 0; index < board.size(); index++) {
            // If it's safe to place a queen at the current position, place the queen and move to the next row
            if (is_Safe(board, row, index)) {
                board[row][index] = 'Q';
                placequeen(board, row + 1);
                board[row][index] = '.'; // Backtrack
            }
        }
    }
    
    // Function to find the total number of distinct solutions for the N-Queens problem
    int totalNQueens(int n) {
        if (n <= 0)
            return res.size(); // If n is non-positive, return the number of solutions found
        
        vector<string> board(n, string(n, '.')); // Initialize an empty chessboard of size n x n
        placequeen(board, 0); // Start placing queens from the first row
        
        return res.size(); // Return the total number of distinct solutions found
    }
};

int main() {
    Solution solution;
    int n;
    
    // Prompt the user to enter the value of n
    cout << "Enter the value of n: ";
    cin >> n;
    
    // Call the totalNQueens method to find the total number of distinct solutions for the N-Queens problem
    int total_solutions = solution.totalNQueens(n);
    
    // Print the result
    cout << "Total distinct solutions for the " << n << "-queens puzzle: " << total_solutions << endl;
    
    return 0;
}
