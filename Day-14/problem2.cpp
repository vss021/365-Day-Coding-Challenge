#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
  
    /*
    Approach 1:
    TC => O(N)
    Sp => O(N)
    */
    int NonRepeatingElement(vector<int>& arr) {
        unordered_map<int, int> mp;
    
        // Count the occurrences of each element in the array
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
    
        // Iterate through the map to find the first element with count 1
        for (auto x : mp) {
            if (x.second == 1) {
                return x.first;
            }
        }

        // If no non-repeating element is found, return -1
        return -1;
    }
    

    /*
   

   Approach 2:
   - We use a bitwise approach to find the element that appears exactly once while all other elements appear thrice.
   - For each bit position, we count the number of set bits in that position for all elements.
   - If the count is not a multiple of 3, then the bit at that position in the answer is set.

   Time Complexity: O(N)
   - We iterate over each element in the array once.
   - The inner loop runs 32 times (for each bit position).

   Space Complexity: O(1)
   - Constant space is used as we are not using any additional data structures.
*/

    int singleElement(int arr[], int N) {
        int ans = 0;
    
        for (int i = 0; i < 32; i++) {
            int count = 0;
    
            // Count the number of set bits at the i-th position for all elements
            for (int j = 0; j < N; j++) {
                if ((arr[j] & (1 << i)) != 0) {
                    count++;
                }
            }
    
            // If the count is not a multiple of 3, set the bit in the answer
            if (count % 3 == 1) {
                ans = ans | (1 << i);
            }
        }
    
        return ans;
    }

};

int main() {
    // Example usage of NonRepeatingElement function
    Solution solution;

    // Example input vector
    vector<int> arr1 = {1, 2, 3, 4, 2, 3, 1, 5};

    // Calculate the non-repeating element using Approach 1
    int result1 = solution.NonRepeatingElement(arr1);

    // Display the result
    if (result1 != -1) {
        cout << "Non-repeating element using Approach 1: " << result1 << endl;
    } else {
        cout << "No non-repeating element found using Approach 1." << endl;
    }

    // Example usage of singleElement function (Approach 2)
    int arr2[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5};
    int N = sizeof(arr2) / sizeof(arr2[0]);

    // Calculate the single element using Approach 2
    int result2 = solution.singleElement(arr2, N);

    // Display the result
    cout << "Single element using Approach 2: " << result2 << endl;

    return 0;
}
