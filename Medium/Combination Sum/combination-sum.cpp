//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void sub(vector<int>&A, int index, vector<vector<int>> &ans, vector<int>&temp, int target){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            
            if(target < 0 || index == A.size()){
                return;
            }
            sub(A,index+1,ans,temp,target);
            
            temp.push_back(A[index]);
            sub(A,index,ans,temp,target-A[index]);
            temp.pop_back();
        }
        vector<vector<int> > combinationSum(vector<int> &A, int B) {
            sort(A.begin(),A.end());
            vector<int> arr;
            arr.push_back(A[0]);
            for(int i=1; i<A.size(); i++){
                if(A[i] != arr.back()){
                    arr.push_back(A[i]);
                }
            }
            vector<vector<int>> ans;
            vector<int> temp;
            sub(arr,0,ans,temp,B);
            sort(ans.begin(),ans.end());
            return ans;
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends