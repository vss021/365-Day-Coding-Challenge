#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the size of the largest subsquare made of 'X's
    int largestSubsquare(int n, vector<vector<char>>& grid) {
        // Initialize vectors to store information about right and bottom edges of 'X's
        vector<vector<int>> rightEdges(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> bottomEdges(n + 1, vector<int>(n + 1, 0));

        // Calculate right edges
        for (int row = 0; row < n; ++row) {
            for (int col = n - 1; col >= 0; --col) {
                if (grid[row][col] == 'X') {
                    rightEdges[row][col] = rightEdges[row][col + 1] + 1;
                }
            }
        }

        // Calculate bottom edges
        for (int col = 0; col < n; ++col) {
            for (int row = n - 1; row >= 0; --row) {
                if (grid[row][col] == 'X') {
                    bottomEdges[row][col] = bottomEdges[row + 1][col] + 1;
                }
            }
        }

        // Find the largest subsquare size
        int largestSize = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int maxSize = min(rightEdges[row][col], bottomEdges[row][col]);
                while (maxSize > 0) {
                    int x1 = row;
                    int y1 = col + maxSize - 1;
                    int x2 = row + maxSize - 1;
                    int y2 = col;
                    if (min(bottomEdges[x1][y1], rightEdges[x2][y2]) >= maxSize) {
                        largestSize = max(largestSize, maxSize);
                        break;
                    } else {
                        --maxSize;
                    }
                }
            }
        }
        return largestSize;
    }
};

int main() {
    // Example usage
    int n = 4;
    vector<vector<char>> grid = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'}
    };

    Solution sol;
    int largestSubsquareSize = sol.largestSubsquare(n, grid);
    cout << "Size of the largest subsquare: " << largestSubsquareSize << endl;

    return 0;
}
