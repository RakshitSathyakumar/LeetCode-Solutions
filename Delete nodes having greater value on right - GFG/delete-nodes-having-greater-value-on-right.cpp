//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node *head){
        Node* temp=head;
        Node *prevs=NULL,*curr=head;
        while(curr){
            Node* frwd=curr->next;
            curr->next=prevs;
            prevs=curr;
            curr=frwd;
        }
        return prevs;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node* temp=head;
        Node* prevs=NULL;
        while(temp){
            if(!prevs){
                prevs=temp;
                temp=temp->next;
                continue;
            }
            if(prevs->data > temp->data){
                prevs->next=temp->next;
                temp=temp->next;
            }else{
                prevs=temp;
                temp=temp->next;
            }
        }
        head=reverse(head);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends