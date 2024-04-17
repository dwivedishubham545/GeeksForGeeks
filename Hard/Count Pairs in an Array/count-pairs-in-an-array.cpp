//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
     int merge(int arr[],int l,int m,int r){
        int inv=0;
        int n1=m-l+1;
        int n2=r-m;
        
        int a[n1];
        int b[n2];
    
        for(int i=0;i<n1;i++){
            a[i]=arr[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i]=arr[m+1+i];
        }
        
        int k=l,i=0,j=0;
        
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                arr[k]=a[i];
                i++;
                k++;
            }
            else{
                arr[k]=b[j];
                inv+=(n1-i);
                j++;
                k++;
                
            }
            
        }
        while(i<n1){
            arr[k]=a[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k]=b[j];
            j++;
            k++;
        }
        
        return(inv);
        
    }
    
    
    int mergeSort(int arr[],int l,int r){
        int inv=0;
        if(l<r){
            int m=(l+r)/2;
            inv+=mergeSort(arr,l,m);
            inv+=mergeSort(arr,m+1,r);
            inv+=merge(arr,l,m,r);
        }
        
        
        return(inv);
    }
    
    
    int countPairs(int arr[] , int n ){
        for(int i=0;i<n;i++){
            arr[i]*=i;
        }
        return(mergeSort(arr,0,n-1));
   
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends