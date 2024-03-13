#include <iostream>

using namespace std;

int findPivotInteger(int n) {
    int totalSum = n * (n + 1) / 2;
    int leftSum = 0;

    for (int x = 1; x <= n; x++) {
        leftSum += x;
        int rightSum = totalSum - leftSum;

        if (leftSum == rightSum) {
            return x;
        }
    }

    return -1;
}

int main() {
    int n = 10; // Example input
    cout << "Pivot Integer for n = " << n << ": " << findPivotInteger(n) << endl;
    return 0;
}
