//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int sum(int ind, int nums[], vector<int> &dp){
        if(ind ==0 ){
            return nums[ind];
        }
        if(ind < 0){
            return 0;
        }
    
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + sum(ind - 2, nums, dp);
        int not_pick = 0 + sum(ind - 1, nums, dp);
        return dp[ind] = max(pick, not_pick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
        vector<int>dp(n+1,-1);
        return sum(n-1, arr, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends