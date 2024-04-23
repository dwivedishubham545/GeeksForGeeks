//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        int i = 1;
        int a = 1;
        int b = 1;
        int c = 1;
        int d = 0;
        int t1, t2;
        while (i < n) {
            t1 = a%1000000007;
            t2 = c%1000000007;
            
            a = (t1 + t2)%1000000007;
            b = t1; 
            c = t1; 
            d = t2;
            
            i++;
        }
        
        return c%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends