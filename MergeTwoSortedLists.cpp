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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* res;
        ListNode* result = new ListNode(0);
        res = result;
        while(l1!=NULL&&l2!=NULL){
           if(l1->val <= l2->val) {
               res->next = l1;
               res = res->next;
               l1 = l1->next; 
           }
           else {
               res->next = l2;
               res = res->next;
               l2 = l2->next; 
               
           }
        }
       if(l1 == NULL) res->next = l2;
       if(l2 == NULL) res->next = l1;
       return result->next;     
            
        
    }
};