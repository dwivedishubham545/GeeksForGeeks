//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char, int> maps;
        for (int i = 0; i < s.length(); i++){
            maps[s[i]]++;
        }
        for (int i = 0; i < k; i++){
            char c = '\0';
            int max = INT_MIN;
            for(const auto& pair: maps){
                if(pair.second > max){
                    max = pair.second;
                    c = pair.first;
                }
            }
            maps[c]--;
        }
        int res = 0;
        for (int i = 0; i < s.length(); i++){
            res += pow(maps[s[i]], 2);
            maps[s[i]] = 0;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends