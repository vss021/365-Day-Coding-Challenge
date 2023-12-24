#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to maximize the number of products that can be bought with a given budget
int buyMaximumProducts(int n, int k, int price[]) {
    // Step 1: Create a vector of pairs to store prices along with their original indices
    vector<pair<int, int>> pricesWithIndices;

    for (int i = 0; i < n; i++) {
        pricesWithIndices.push_back(make_pair(price[i], i));
    }

    // Step 2: Sort the vector of pairs based on price in ascending order
    sort(pricesWithIndices.begin(), pricesWithIndices.end());

    // Step 3: Initialize variables for answer and count
    int totalCost = 0;
    int totalCount = 0;

    // Step 4: Iterate through the sorted vector and buy products until the budget is exhausted
    for (int i = 0; i < n; i++) {
        // Buy products until the budget is exhausted or the stock of the current product is depleted
        for (int j = 0; j <= pricesWithIndices[i].second; j++) {
            if (totalCost <= k) {
                totalCost += pricesWithIndices[i].first;
                totalCount++;
            } else {
                break; // Budget exhausted, exit the inner loop
            }
        }

        if (totalCost > k) {
            break; // Budget exhausted, exit the outer loop
        }
    }

    // Step 5: Return the maximum number of products that can be bought within the budget
    return totalCount - 1;
}

int main() {
    // Example usage
    int n = 5;
    int k = 50;
    int price[] = {10, 2, 5, 7, 15};

    cout << "Maximum number of products that can be bought: " << buyMaximumProducts(n, k, price) << endl;

    return 0;
}
