#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> recamanSequence(int n) {
    // Initialize a set to store visited numbers
    set<int> visitedNumbers;
    visitedNumbers.insert(0); // Insert 0 as the starting point
    
    // Initialize the resulting sequence vector with size n and fill it with 0s
    vector<int> sequence(n, 0);
    
    // Generate the Recaman sequence
    for (int i = 1; i < n; i++) {
        // If the condition is met, choose the previous element minus the current index
        if (sequence[i - 1] - i > 0 && visitedNumbers.find(sequence[i - 1] - i) == visitedNumbers.end()) {
            sequence[i] = sequence[i - 1] - i;
            visitedNumbers.insert(sequence[i]); // Mark the chosen number as visited
        }
        // If the condition is not met, choose the previous element plus the current index
        else {
            sequence[i] = sequence[i - 1] + i;
            visitedNumbers.insert(sequence[i]); // Mark the chosen number as visited
        }
    }
    
    return sequence;
}

int main() {
    int n;
    cout << "Enter the number of elements you want in Recaman sequence: ";
    cin >> n;
    
    vector<int> recaman = recamanSequence(n);
    
    // Print the generated Recaman sequence
    cout << "Recaman Sequence:";
    for (int i = 0; i < n; i++) {
        cout << " " << recaman[i];
    }
    cout << endl;
    
    return 0;
}
