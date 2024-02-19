//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string s=arr[0];
        for(int i=1;i<N;i++){
            string ans="";
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==s[j] && j<s.size()){
                ans+=arr[i][j];
                
                }
                else
                break;
                
            }
            s=ans;
        }
        if(!s.empty())
        return s;
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends