//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.length() == k)
      return "0";

    string ans;
    vector<char> stack;

    for (int i = 0; i < num.length(); ++i) {
      while (k > 0 && !stack.empty() && stack.back() > num[i]) {
        stack.pop_back();
        --k;
      }
      stack.push_back(num[i]);
    }

    while (k-- > 0)
      stack.pop_back();

    for (const char c : stack) {
      if (c == '0' && ans.empty())
        continue;
      ans += c;
    }

    return ans.empty() ? "0" : ans;
  }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends