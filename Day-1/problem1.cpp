#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Approach:
    1. Create a vector of pairs where each pair contains the finish time and the index of the meeting.
    2. Sort the vector of pairs based on finish times in ascending order.
    3. Initialize a time variable 'tl' with the finish time of the first meeting.
    4. Iterate through the sorted pairs and select meetings that don't overlap with the previous one.
    5. Store the selected meeting indices in a vector 'ans'.
    6. Sort the 'ans' vector for the final result.
    7. Return the vector containing the indices of the selected meetings.
*/

vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f) {
    // Step 1: Create a vector of pairs (finish time, index)
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({f[i], i});
    }

    // Step 2: Sort meetings based on finish times
    sort(meetings.begin(), meetings.end());

    // Step 3: Initialize time and result vector
    int tl = meetings[0].first;
    vector<int> ans;
    ans.push_back(meetings[0].second + 1);

    // Step 4: Iterate through sorted pairs and select non-overlapping meetings
    for (int i = 1; i < n; i++) {
        if (s[meetings[i].second] > tl) {
            tl = meetings[i].first;
            ans.push_back(meetings[i].second + 1);
        }
    }

    // Step 6: Sort the result vector
    sort(ans.begin(), ans.end());

    // Step 7: Return the vector containing the indices of selected meetings
    return ans;
}

int main() {
    // Example usage
    int n = 6;
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};

    vector<int> result = maxMeetings(n, s, f);

    // Print the selected meetings
    cout << "Selected Meetings: ";
    for (int meeting : result) {
        cout << meeting << " ";
    }
    cout << endl;

    return 0;
}
