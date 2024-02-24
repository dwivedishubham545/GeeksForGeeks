//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int solve(int n, vector<int>&dp){
            if(n==0||n==1||n==2) return n;
            if(dp[n]!=-1) return dp[n];
            int p = solve(n/2,dp)+ solve(n/3,dp)+solve(n/4,dp);
            return dp[n]= max(n,p);
        }
        int maxSum(int n)
        {
            vector<int>dp(n+1,-1);
            return solve(n,dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends