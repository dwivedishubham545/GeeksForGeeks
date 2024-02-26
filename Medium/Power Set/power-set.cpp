//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    void sub(string s, int index, string current, vector<string>& v) {
        int n = s.length();
        if (index == n) {
            if (!current.empty()) {
                v.push_back(current);
            }
            return;
        }
        sub(s, index + 1, current + s[index], v);
        sub(s, index + 1, current, v);
    }

    vector<string> AllPossibleStrings(string s){
        vector<string> v;
        sub(s, 0, "", v);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends