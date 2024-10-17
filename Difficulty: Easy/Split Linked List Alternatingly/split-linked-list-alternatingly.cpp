//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *temp1 = NULL;
        Node *temp2 = NULL;
        Node *temp = head;
        bool flag = 0;
        
        while(temp != NULL) {
            if(flag == 0) {
                if(head1 == NULL) {
                    head1 = new Node(temp->data);
                    temp1 = head1;
                } else {
                    temp1->next = new Node(temp->data);
                    temp1 = temp1->next;
                }
                flag = 1;
            } else {
                if(head2 == NULL) {
                    head2 = new Node(temp->data);
                    temp2 = head2;
                } else {
                    temp2->next = new Node(temp->data);
                    temp2 = temp2->next;
                }
                flag = 0;
            }
            temp = temp->next;
        }
        
        return {head1, head2};
    }
};



//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends