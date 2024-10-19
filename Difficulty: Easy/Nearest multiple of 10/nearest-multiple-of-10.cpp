//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        char lastDigit = str.back();
    
        if (lastDigit <= '5') { 
            str.back() = '0';
        } else {  
            int i = str.size() - 1;
            str[i] = '0';
            
            while (i > 0 && str[i - 1] == '9') {
                str[i - 1] = '0';
                i--;
            }
            
            if (i > 0) {
                str[i - 1]++;
            } else {
                str = '1' + str;
            }
        }
    
        return str;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends