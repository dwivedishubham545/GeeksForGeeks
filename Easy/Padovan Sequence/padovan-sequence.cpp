//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       int mod=1e9+7;
       int one=1;
       int two=1;
       int three=1;
       int ans=1;
       
       for(int i=3;i<=n;i++){
            ans=(one+two)%mod;
            one=two;
            two=three;
            three=ans;
       }
       
       return ans;
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends