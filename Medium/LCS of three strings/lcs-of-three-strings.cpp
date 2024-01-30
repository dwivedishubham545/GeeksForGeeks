//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int LCSof3 (string x, string y, string z, int n, int m, int l)
        {
            // your code here
            int dp[n][m][l];
            memset(dp, 0, sizeof dp);
            for (int i=0; i<n; i++){ 
                for (int j=0; j<m; j++){ 
                    for (int k=0; k<l; k++){
                        if (x[i] == y[j] && x[i] == z[k])
                            dp[i][j][k] = ((i>0 && j>0 && k>0) ? dp[i-1][j-1][k-1] : 0) + 1;
                        else
                            dp[i][j][k] = max({i>0 ? dp[i-1][j][k] : 0, j>0 ? dp[i][j-1][k] : 0, k>0 ? dp[i][j][k-1] : 0}); 
                        } 
                    } 
                } 
            return dp[n-1][m-1][l-1];
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends