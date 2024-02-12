#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    // Method to calculate the sequence sum
    long long sequence(int n){
        // Initialize the result variable
        long long result = 1;
        
        // Define the modulo value
        int mod = 1e9 + 7;
        
        // Initialize a variable to track the current value
        long long currentValue = 1;
        
        // Special case for n = 1
        if(n == 1){
            return 1;
        }
        
        // Loop through from 2 to n
        for(int i = 2; i <= n; i++)
        {
            // Initialize a temporary variable for the current iteration
            long long temp = 1;
            
            // Iterate 'i' times
            for(int j = i; j > 0; j--)
            {
                // Update the current value
                currentValue++;
                
                // Update the temporary variable
                temp = (temp % mod * currentValue % mod) % mod;
            }
            
            // Update the result by adding the temporary value
            result = (result % mod + temp % mod) % mod;
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test the sequence method
    cout << "Sequence sum for n = 3: " << solution.sequence(3) << endl;
    cout << "Sequence sum for n = 5: " << solution.sequence(5) << endl;
    
    return 0;
}
