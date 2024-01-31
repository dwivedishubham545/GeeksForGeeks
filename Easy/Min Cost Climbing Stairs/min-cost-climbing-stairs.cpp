//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int solve(int ind , vector<int> &cost , vector<int> &dp){
        if(ind == 0 || ind == 1) return 0;
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int one = solve(ind-1 , cost , dp) + cost[ind-1];
        int two = INT_MAX;
        if(ind>1){
            two = solve(ind-2 , cost , dp) + cost[ind-2];   
        }
        dp[ind] = min(one , two);
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        vector<int>dp(N+1,-1);
        return solve(N , cost , dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends