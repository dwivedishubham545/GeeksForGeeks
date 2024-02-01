//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[], int pre[], int n){
        int preIndex = 0;
        return buildTreeUtil(in, pre, 0, n-1, preIndex);
    }
    
    Node* buildTreeUtil(int in[], int pre[], int inStart, int inEnd, int &preIndex){
        if(inStart > inEnd) return NULL;
        
        Node* tNode = new Node(pre[preIndex++]);
        
        if(inStart == inEnd) return tNode;
        
        int inIndex = search(in, inStart, inEnd, tNode->data);
        
        tNode->left = buildTreeUtil(in, pre, inStart, inIndex-1, preIndex);
        tNode->right = buildTreeUtil(in, pre, inIndex+1, inEnd, preIndex);
        
        return tNode;
    }
    
    int search(int arr[], int start, int end, int x){
        for(int i=start; i<=end; i++){
            if(arr[i] == x) return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends