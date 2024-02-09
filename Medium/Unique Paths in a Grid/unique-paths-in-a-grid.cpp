//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  const int mod = 1e9+7;
    int solve(int i,int j , vector<vector<int>>&dp, vector<vector<int>>&grid){
        if(i<0 || j<0 || grid[i][j]==0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j] != -1){
            return dp[i][j]%mod;
        }
        int up = solve(i-1,j,dp,grid);
        int left = solve(i,j-1,dp,grid);
        dp[i][j]= (up+left)%mod;
        return dp[i][j]%mod;    
        
    }
    int uniquePaths(int m , int n, vector<vector<int>>& grid) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends