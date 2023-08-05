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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummyHead = head;
        while(dummyHead->next != NULL){
            ListNode* temp = dummyHead->next;
            int x = __gcd(dummyHead->val,temp->val);
            ListNode* newNode = new ListNode(x);
            dummyHead->next = newNode;
            newNode->next =  temp;
            dummyHead=dummyHead->next->next;
        }
        return head;
    }
};