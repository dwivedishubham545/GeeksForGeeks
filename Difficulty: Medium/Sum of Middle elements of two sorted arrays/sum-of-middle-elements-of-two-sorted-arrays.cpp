//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int low = 0, high = n;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = n - partition1;
    
            int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
            int minRight1 = (partition1 == n) ? INT_MAX : arr1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];
    
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // We've found the correct partitions
                if ((n * 2) % 2 == 0) { // even number of elements
                    int mid1 = std::max(maxLeft1, maxLeft2);
                    int mid2 = std::min(minRight1, minRight2);
                    return mid1 + mid2;
                }
            } else if (maxLeft1 > minRight2) {
                // Move left in arr1
                high = partition1 - 1;
            } else {
                // Move right in arr1
                low = partition1 + 1;
            }
        }
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends