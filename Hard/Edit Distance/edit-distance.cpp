//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string s,string t,int i, int j,vector<vector<int>>&dp){
        if(i==-1&&j==-1) return 0;
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= solve(s,t,i-1,j-1,dp);
        }
        else{
            int k=1+solve(s,t,i-1,j,dp);
            int l=1+solve(s,t,i-1,j-1,dp);
            int m=1+solve(s,t,i,j-1,dp);
            return dp[i][j]=min(k,min(l,m));
        }
      
    }
    int editDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends