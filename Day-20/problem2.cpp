#include <iostream>

class Solution{
public:	

	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int> mp(k,-2);
	    mp[0] = -1;
	    int sum = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	        sum = sum%k;
	        
	        if(sum<0)
	        sum += k;
	        
	        if(mp[sum%k]!=-2)
	        {
	            ans = max(ans,i-mp[sum%k]);
	        }
	        else 
	        mp[sum%k] = i;
	    }
	    return ans;
	}
};

int main() {
    Solution solution;

    // Example 1:
    int arr1[] = {4, 5, 0, -2, -3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 5;
    cout << "Example 1: " << solution.longSubarrWthSumDivByK(arr1, n1, k1) << " (expected: 7)\n";

    // Example 2:
    int arr2[] = {4, 5, 0, -12, -3, 1, -10, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 7;
    cout << "Example 2: " << solution.longSubarrWthSumDivByK(arr2, n2, k2) << " (expected: 8)\n";

    // You can add more test cases as needed

    return 0;
}
