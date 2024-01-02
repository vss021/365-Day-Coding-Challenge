#include <iostream>


class Solution{
    public:    
    long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
    {
        
    
        long long int sum = 0;
        long long int ans = INT_MIN;
        long long int last = 0;
        int  i = 0;
        int  j = 0;
        
        while(j<n) {
            sum += arr[j];
            if((j-i+1)<k) {
                j++;
            }else if((j-i+1) == k) {
                ans = max(ans, sum);
                j++;
            }else if((j-i+1) > k) {
                ans = max(ans, sum);
                last += arr[i];
                i++;
                if(last < 0) {
                    sum -= last;
                    ans = max(ans, sum);
                    last = 0;
                }
                j++;
            }
            
        }
        return ans;        
    }
};

int main() {
    Solution solution;
    
    // Example input
    long long int arr[] = {1, -2, 3, 4, -5, 6};
    long long int n = sizeof(arr) / sizeof(arr[0]);
    long long int k = 3;

    // Calling the maxSumWithK function
    long long int result = solution.maxSumWithK(arr, n, k);

    // Displaying the result
    std::cout << "Maximum sum of subarray with length " << k << ": " << result << std::endl;

    return 0;
}
