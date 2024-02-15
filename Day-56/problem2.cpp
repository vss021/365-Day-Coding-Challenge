#include <iostream>
#include <vector>

class Solution {
public:
    int isPossible(std::vector<std::vector<int>>& paths) {
        // Get the number of cities
        int n = paths.size();

        // Iterate over each city
        for (int i = 0; i < n; i++) {
            // Count the number of outgoing paths from the current city
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (paths[i][j] == 1) {
                    count++;
                }
            }

            // If the count of outgoing paths is odd, return 0
            if (count % 2 != 0) {
                return 0;
            }
        }

        // All cities have an even count of outgoing paths
        return 1;
    }
};

int main() {
    // Example usage
    std::vector<std::vector<int>> paths = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };

    Solution solution;
    int result = solution.isPossible(paths);
    if (result) {
        std::cout << "It's possible to traverse all cities with even number of outgoing paths." << std::endl;
    } else {
        std::cout << "It's not possible to traverse all cities with even number of outgoing paths." << std::endl;
    }

    return 0;
}
