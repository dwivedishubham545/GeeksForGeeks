//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int Mod = 1e9+7;
    int spaceOptimised(string& s, string& t) {
        int n = s.length(), m = t.length();
        vector<int> curr(m+1, 0), next(m+1, 0);
        for(int i=0; i<=n; i++) {
            curr[m] = 1;
            next[m] = 1;
        }
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == t[j]) {
                    ans = (ans % Mod + next[j+1] % Mod) % Mod;
                }
                ans = ans % Mod + next[j] % Mod;
                curr[j] = ans % Mod;
            }
            next = curr;
        }
        return curr[0];
    }
    int subsequenceCount(string s, string t)
    {
        return spaceOptimised(s, t);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends