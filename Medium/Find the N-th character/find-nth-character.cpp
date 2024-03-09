//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        char ans=s[n/(1<<r)];
        for(int i=0;i<r;i++){
            if(n%2){
                if(ans=='1')ans='0';
                else ans='1';
            }
            n/=2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
