#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs( Pair& a,  Pair& b) {
    return a.first < b.first;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int arraySize_;

        cin >> arraySize_;

        vector<int> Array_elements(arraySize_);
        
        map<int, vector<int>> elementPositions;

        for (int i = 0; i < arraySize_; i++) {
            cin >> Array_elements[i];
            elementPositions[Array_elements[i]].push_back(i);
        }

        int result = arraySize_;
        int lastPosition = arraySize_ + 1;

        vector<Pair> sortedPositions;
        for ( auto& entry : elementPositions) {
            sortedPositions.push_back({entry.first, entry.second[0]});
        }

        sort(sortedPositions.begin(), sortedPositions.end(), comparePairs);

        for ( auto& pair : sortedPositions) {
            int value = pair.first;
             vector<int>& positions = elementPositions[value];
            int p = lower_bound(positions.begin(), positions.end(), lastPosition) - positions.begin();

            if (p > 0) {
                p--;
                arraySize_ -= p + 1;
                result = min(result, arraySize_ + value);
                lastPosition = elementPositions[value][0];
            }
        }

        cout << result << '\n';
    }

    return 0;
}
