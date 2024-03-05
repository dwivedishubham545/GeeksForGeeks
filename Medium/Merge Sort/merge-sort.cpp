//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r){
        int an = m - l + 1;
        int bn = r - m;
        int a[an];
        int b[bn];
        for (int i = 0; i < an; i++){
            a[i] = arr[l + i];
        }
        for (int j = 0; j < bn; j++){
            b[j] = arr[m + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = l;
        while (i < an && j < bn){
            if (a[i] < b[j]){
                arr[k++] = a[i++];
            }
            else{
                arr[k++] = b[j++];
            }
        }
        while (i < an){
            arr[k++] = a[i++];
        }
        while (j < bn){
            arr[k++] = b[j++];
        }
    }
    public:
    void mergeSort(int arr[], int low, int high)
    {
        if(low==high) return;
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends