#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using TimePersonPair = pair<int, int>; // Alias for pair representing time and person
    using Graph = vector<vector<TimePersonPair>>; // Alias for the graph representation

    // Time Complexity: O(E*log(V)), where E is the number of edges and V is the number of vertices
    // Space Complexity: O(V)
    vector<int> findPeopleAwareOfSecret(int n, vector<vector<int>>& meetings, int firstPerson) {
        Graph graph(n); // Graph representing meetings
        // Create the graph between the persons
        for (const auto& meeting : meetings) {
            int person1 = meeting[0], person2 = meeting[1], time = meeting[2];
            graph[person1].push_back({person2, time});
            graph[person2].push_back({person1, time});
        }

        // Min heap to prioritize meetings by time
        priority_queue<TimePersonPair, vector<TimePersonPair>, greater<TimePersonPair>> minHeap;
        // Initialize heap with the initial meeting of firstPerson and time 0
        minHeap.push({0, firstPerson});
        minHeap.push({0, 0});

        vector<int> awarePeople; // Result vector to store people aware of the secret
        vector<bool> visited(n, false); // Mark persons as visited after they've known the secret
        
        while (!minHeap.empty()) {
            auto [time, person] = minHeap.top();
            minHeap.pop();

            // Skip if the person is already visited
            if (visited[person]) continue;
            visited[person] = true;

            // Add new potential persons to the heap if they haven't known the secret yet
            for (const auto& neighbor : graph[person]) {
                int neighborPerson = neighbor.first, neighborTime = neighbor.second;
                if (!visited[neighborPerson] && time <= neighborTime) {
                    minHeap.push({neighborTime, neighborPerson});
                }
            }
        }

        // Populate the result with people aware of the secret
        for (int i = 0; i < n; ++i) {
            if (visited[i]) awarePeople.push_back(i);
        }
        return awarePeople;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        return findPeopleAwareOfSecret(n, meetings, firstPerson);
    }
};



int main() {
    // Example usage of the Solution class
    Solution solution;
    
    // Example meetings data
    vector<vector<int>> meetings = {
        {0, 1, 5},
        {1, 2, 8},
        {2, 3, 6},
        {3, 4, 7},
        {4, 5, 9}
    };

    int firstPerson = 0;
    int totalPersons = 6;

    vector<int> awarePeople = solution.findAllPeople(totalPersons, meetings, firstPerson);

    cout << "People aware of the secret: ";
    for (int person : awarePeople) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}
