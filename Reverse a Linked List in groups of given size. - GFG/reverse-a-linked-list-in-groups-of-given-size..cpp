//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    // struct node *reveseLL(struct node *&head){
    //     struct node *prevs=NULL,curr=head,frwd=head;
    //     while(curr != NULL){
    //         frwd=curr->next;
    //         curr->next=prevs;
    //         prevs=curr;
    //         curr=frwd;
    //     }
    //     return prevs;
    // }
    struct node *krev(struct node *&head,int k){
        if(head == NULL) return NULL;
        
        int cnt=0;
        struct node *prevs=NULL,*curr=head,*frwd=head;
        while(curr != NULL && cnt < k){
            frwd=curr->next;
            curr->next=prevs;
            prevs=curr;
            curr=frwd;
            cnt++;
        }
        if(frwd != NULL){
            head->next = krev(frwd,k);
        }
        return prevs;
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(!head) return NULL;
        return krev(head,k);
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends