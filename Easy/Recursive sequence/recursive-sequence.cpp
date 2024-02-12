//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int mod= 1e9+7;
    long long solve(int n){
        long long x=1;
        long long f=0;
        for(int i=1;i<=n;i++){
            long long m = 1;
            for(int j=1;j<=i;j++){
                m=(m*(x++))%mod;
            }
            f=(f+m)%mod;
        }
        return f;
    }
    long long sequence(int n){
        return solve(n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends