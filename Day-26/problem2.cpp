#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand function
#include <ctime>   // For seeding rand function
using namespace std;

class RandomizedSet {
    vector<int> elements;
    unordered_map<int, int> elementIndexMap;

public:
    // Constructor
    RandomizedSet() {
        // Seed the random number generator
        srand(time(0));
    }

    // Check if the set contains a given value
    bool contains(int val) {
        return elementIndexMap.find(val) != elementIndexMap.end();
    }

    // Insert a value into the set
    bool insert(int val) {
        if (contains(val))
            return false;

        // Add the value to the end of the vector
        elements.push_back(val);
        // Update its index in the map
        elementIndexMap[val] = elements.size() - 1;
        return true;
    }

    // Remove a value from the set
    bool remove(int val) {
        if (!contains(val))
            return false;

        // Find the index of the value in the vector
        int index = elementIndexMap[val];

        // Swap the value with the last element in the vector
        elements[index] = elements.back();
        // Update the index of the swapped element in the map
        elementIndexMap[elements.back()] = index;

        // Remove the last element from the vector
        elements.pop_back();
        // Erase the value from the map
        elementIndexMap.erase(val);

        return true;
    }

    // Get a random element from the set
    int getRandom() {
        return elements[rand() % elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    // Create a RandomizedSet object
    RandomizedSet* obj = new RandomizedSet();

    // Insert elements into the set
    obj->insert(1);
    obj->insert(2);
    obj->insert(3);

    // Check if an element is in the set
    int valToSearch = 2;
    bool containsVal = obj->contains(valToSearch);
    std::cout << "Set contains " << valToSearch << ": " << std::boolalpha << containsVal << std::endl;

    // Remove an element from the set
    int valToRemove = 2;
    bool removed = obj->remove(valToRemove);
    std::cout << "Remove " << valToRemove << ": " << std::boolalpha << removed << std::endl;

    // Get a random element from the set
    int randomVal = obj->getRandom();
    std::cout << "Random element: " << randomVal << std::endl;

    // Clean up and free memory
    delete obj;

    return 0;
}
