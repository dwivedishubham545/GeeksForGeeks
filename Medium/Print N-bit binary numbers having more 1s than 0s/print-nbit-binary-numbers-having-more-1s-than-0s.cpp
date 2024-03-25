//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(int cnt1,int cnt0,vector<string> &v,string s,int n){
        if(cnt1<cnt0)return;
        if(s.size()==n)
        {
        v.push_back(s);
        return;
        }
        solve(cnt1+1,cnt0,v,s+'1',n);
        solve(cnt1,cnt0+1,v,s+'0',n);
    }
    vector<string> NBitBinary(int n){
        vector<string> v;
        string s="1";
        solve(1,0,v,s,n);
        return v;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends