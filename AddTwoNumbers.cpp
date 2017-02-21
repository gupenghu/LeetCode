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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new  ListNode(0);
        ListNode* ptl = result;
        bool carry = false;
         int a = 0;
         int b = 0;
        while(l1!= NULL || l2!= NULL){
            a = 0;
            b = 0;
		    if(l1) a = l1->val;
		    if(l2) b = l2->val;
    
            ListNode *temp = new  ListNode((a + b + carry)%10 );
            ptl->next =  temp;
            ptl = temp;

            if(a + b + carry >= 10) {
                carry = true; 
            }
            else{
                carry = false;
            }

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
       if(carry) {
           ListNode *temp = new  ListNode(1);
           ptl->next = temp;
       }
       return result->next;
    }
};