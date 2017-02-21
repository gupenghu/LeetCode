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
    ListNode* swapPairs(ListNode* head) {
        ListNode *before = new ListNode(0);
        ListNode *result = before;
        before->next = head;
        ListNode *currnode = head;
        ListNode *nextnode = NULL;
        while(currnode != NULL){
            nextnode = currnode->next;
            if(nextnode == NULL) return result->next;
            before->next = nextnode;
            ListNode *temp = nextnode->next;
            nextnode->next = currnode;
            currnode->next = temp;
            before = currnode;
            currnode = currnode->next;
        }
        return result->next;
    }
};