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
    ListNode* partition(ListNode* head, int x) {
//         day 100
        ListNode* left = new ListNode(0);ListNode *right = new ListNode(0);
        ListNode* temp = head,*leftTail = left,*rightTail=right;
        while(temp){
            if(temp->val >= x){
                rightTail->next=temp;
                rightTail=rightTail->next;
            }else{
                leftTail->next=temp;
                leftTail = leftTail->next;
            }
            temp=temp->next;
        }
        leftTail->next = right->next;
        rightTail->next = NULL;
        return left->next;
    }
};