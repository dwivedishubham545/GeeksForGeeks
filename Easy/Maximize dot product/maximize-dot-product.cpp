//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) { 
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i=1;i<(n+1);i++)
		{
		    for(int j=1;j<(m+1);j++)
		    {
		        if(i==0 or j==0)
		        continue;
		        
	             else if(i==j){
	                 dp[i][j]=a[i-1]*b[j-1]+dp[i-1][j-1];
	             }
	             else if(i>j){
	                 dp[i][j]=max(a[i-1]*b[j-1]+dp[i-1][j-1],dp[i-1][j]);
	             }
		    }
		}
		
		return dp[n][m];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends