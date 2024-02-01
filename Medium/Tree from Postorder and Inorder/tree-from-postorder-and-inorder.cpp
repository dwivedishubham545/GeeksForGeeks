//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int search(int arr[], int start, int end, int x){
        for(int i=start; i<=end; i++){
            if(arr[i] == x) return i;
        }
        return -1;
    }
Node* solve(int in[], int post[],int &postIndex, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;
        
        Node* tNode = new Node(post[postIndex--]);
        
        if(inStart == inEnd) return tNode;
        
        int inIndex = search(in, inStart, inEnd, tNode->data);
        
        tNode->right = solve(in, post, postIndex, inIndex+1, inEnd);
        tNode->left = solve(in, post, postIndex, inStart, inIndex-1);
        
        return tNode;
    }
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    Node* ans = solve(in, post, postOrderIndex, 0, n-1);
    return ans;
}
