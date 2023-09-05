/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int data)
    {
        Node* temp=new Node(data);
        if(cloneHead == NULL)
        {
            cloneHead=temp;
            cloneTail=temp;
            return;
        }
        else
        {
            cloneTail->next=temp;
            cloneTail=temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp != NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }

        unordered_map<Node* , Node*> ump;
        Node* ctemp= cloneHead;
        temp=head;

        //create a map , mapping the original LL and clone LL

        while(temp != NULL)
        {
            ump[temp]=ctemp;
            temp=temp->next;
            ctemp=ctemp->next;
        }

        //restoring the heads for random pointers;
        ctemp=cloneHead;
        temp=head;

        //cloning the random pointers now..

        while(temp != NULL)
        {
            ctemp->random=ump[temp->random];
            ctemp=ctemp->next;
            temp=temp->next;
        }
        return cloneHead;
    }
};