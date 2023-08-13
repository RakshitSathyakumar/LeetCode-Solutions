/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* &head){
        ListNode*curr=head,*prevs=NULL;
        while(curr){
            ListNode* frwd = curr->next;
            curr->next = prevs;
            prevs=curr;
            curr=frwd;
        }
        return prevs;
    }
    ListNode* doubleIt(ListNode* Head) {
        
        ListNode* head = rev(Head);
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyHead = dummy;ListNode *temp=head;
        int carry =0;
        while(temp != NULL){
            int value = (temp->val)*2 + carry;
            int newValue = (value)%10;
            carry=value/10;
            ListNode* newNode = new ListNode(newValue);
            dummyHead->next = newNode;
            dummyHead=dummyHead->next;
            temp=temp->next;
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            dummyHead->next = newNode;
        }
        ListNode* ans = rev(dummy->next);
        return ans;
    }
};