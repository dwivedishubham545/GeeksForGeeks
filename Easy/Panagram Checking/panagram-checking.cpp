//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
         int i;
        vector<int>v(26,0);
        for(i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
            if(s[i]>='a' && s[i]<='z')
            v[s[i]-97]++;
        }
        for(i=0;i<v.size();i++)
        {
            if(v[i] == 0)
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends