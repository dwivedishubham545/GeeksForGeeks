//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        if(n <= 2) return 0;
        long long int waterTrapped = 0;
        int left = 0, right = n - 1;
        int maxLeft = arr[left], maxRight = arr[right];
    
        while(left < right) {
            if(arr[left] < arr[right]) {
                left++;
                maxLeft = max(maxLeft, arr[left]);
                waterTrapped += maxLeft - arr[left];
            } else {
                right--;
                maxRight = max(maxRight, arr[right]);
                waterTrapped += maxRight - arr[right];
            }
        }
        return waterTrapped;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends