#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compareItems(const Item& a, const Item& b) {
    return (double(a.value) / a.weight) > (double(b.value) / b.weight);
}

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int capacity, Item items[], int numItems) {
        // Sort items based on value-to-weight ratio in descending order
        sort(items, items + numItems, compareItems);

        int remainingCapacity = capacity;
        double totalValue = 0.0;

        // Iterate through sorted items
        for (int i = 0; i < numItems; ++i) {
            // Check if the entire item can be included in the knapsack
            if (remainingCapacity >= items[i].weight) {
                totalValue += items[i].value;
                remainingCapacity -= items[i].weight;
            } else {  // Include a fraction of the item to fill the remaining capacity
                totalValue += remainingCapacity * (double(items[i].value) / items[i].weight);
                break;  // Break the loop since the knapsack is full
            }
        }

        return totalValue;
    }
};


int main() {
    // Example usage of the Solution class
    Solution knapsackSolver;

    // Example items with values and weights
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};

    // Number of items
    int numItems = sizeof(items) / sizeof(items[0]);

    // Knapsack capacity
    int capacity = 50;

    // Calculate the maximum total value using fractional knapsack
    double maxValue = knapsackSolver.fractionalKnapsack(capacity, items, numItems);

    // Display the result
    std::cout << "Maximum total value in the knapsack: " << maxValue << std::endl;

    return 0;
}
