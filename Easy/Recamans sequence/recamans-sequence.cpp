//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        unordered_map<int,int> mp;
        vector<int> ans(n);
        
        ans[0] = 0;
        ans[1] = 1;
        
        mp[0] = 0;
        mp[1] = 1;
        
        for(int i =2; i<n; i++)
        {
            int x = ans[i-1] -i;
            
            if(x > 0 && mp[x] == 0)
            {
                ans[i] = x;
                mp[x]++;
            }
            
            else
            {
                x = ans[i-1] + i;
                ans[i] = x;
                mp[x]++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends