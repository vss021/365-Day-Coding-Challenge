#include <iostream>
using namespace std;

int totalCount = 0;

void generateSequences(int current, int maxLimit, int remainingSteps) {
    if (current <= maxLimit) {
        if (remainingSteps == 1) {
            totalCount++;
            return;
        }

        for (int next = 2 * current; next <= maxLimit; next++) {
            generateSequences(next, maxLimit, remainingSteps - 1);
        }
    }
}

int countNumberSequences(int maxLimit, int stepCount) {
    totalCount = 0;

    for (int start = 1; start <= max(maxLimit, stepCount); start++) {
        generateSequences(start, maxLimit, stepCount);
    }

    return totalCount;
}

int main() {
    int maxLimit = 5;
    int stepCount = 3;

    int result = countNumberSequences(maxLimit, stepCount);

    cout << "Total Sequences: " << result << endl;

    return 0;
}
