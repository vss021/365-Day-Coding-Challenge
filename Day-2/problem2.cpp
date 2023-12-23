#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Approach:
1. Initialize coordinates (x, y) at (0, 0) and a set to store visited points.
2. Traverse the path string character by character.
3. Update coordinates based on the current character ('N', 'S', 'E', 'W').
4. Check if the current coordinates have been visited before. If yes, return true.
5. Otherwise, mark the current coordinates as visited.
6. If the loop completes without returning, return false.

Time complexity: O(n), where n is the length of the input path.
Space complexity: O(n), to store visited coordinates.
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_map<int, unordered_set<int>> visited = {{x, {y}}};

        for (auto& direction : path) {
            // Update coordinates based on the current direction
            if (direction == 'N') y++;
            else if (direction == 'S') y--;
            else if (direction == 'E') x++;
            else x--;

            // Check if the current coordinates have been visited before
            if (visited.count(x) != 0 && visited[x].count(y) != 0) {
                return true;
            }

            // Mark the current coordinates as visited
            visited[x].insert(y);
        }

        return false;
    }
};

int main() {
    // Example usage
    Solution solution;
    string path = "NESW";
    bool result = solution.isPathCrossing(path);

    cout << "Does the path cross itself? " << (result ? "Yes" : "No") << endl;

    return 0;
}
