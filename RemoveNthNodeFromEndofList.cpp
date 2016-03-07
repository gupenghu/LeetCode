/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* pfirst = head,* psecond = head,*temp;
       while(n--)  psecond = psecond->next;
       if(psecond == NULL) return head->next;
       while(psecond->next != NULL){
           pfirst = pfirst->next;
           psecond = psecond->next;
       }
       temp =  pfirst->next;
       pfirst->next = pfirst->next->next;
       delete temp;
       return head;
    }
};