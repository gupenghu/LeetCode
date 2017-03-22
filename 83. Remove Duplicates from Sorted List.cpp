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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next ==  NULL) return head;
		ListNode* result = new ListNode(0);
		result->next = head;
		ListNode* last_node = result;
		result->next = head;
		ListNode* temp = head;
		int val = temp->val;
	   
		while(temp->next){
			if(val == temp->next->val) {
				last_node->next = temp->next;
			}
			else last_node = temp;
			temp = temp->next;
			val = temp->val;
		}
		return result->next;
	}
};