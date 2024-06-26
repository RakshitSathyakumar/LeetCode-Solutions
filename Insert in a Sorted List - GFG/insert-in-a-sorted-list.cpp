//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        struct Node* dummy = new struct Node(-1);
        // dummy->data = -1;
        dummy->next = head;
        struct Node* dummyHead = dummy;
        bool f = false;
    
        while (head) {
            if (data < head->data) {
                f = true;
                struct Node* newDataNode = new struct Node(data);
                newDataNode->data = data;
                newDataNode->next = head;
                dummyHead->next = newDataNode;
                break; // Since the list is sorted, we can break here.
            } else {
                dummyHead = head;
                head = head->next;
            }
        }
    
        if (!f) {
            struct Node* newDataNode = new struct Node(data);
            newDataNode->data = data;
            newDataNode->next = nullptr;
            dummyHead->next = newDataNode;
        }

    return dummy->next;
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
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends