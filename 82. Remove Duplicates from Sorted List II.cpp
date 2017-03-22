// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 

// For example,
//  Given 1->2->3->3->4->4->5, return 1->2->5.
//  Given 1->1->1->2->3, return 2->3. 



// Subscribe to see which companies asked this question.

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
	   	bool same = false;
		while(temp->next){
			if(val == temp->next->val) {
				last_node->next = temp->next;
				same = true;
			}else if (same == true)
			{
				last_node->next = temp->next;
				same = false;
			}
			else last_node = temp;
			temp = temp->next;
			val = temp->val;
		}
		if (same == true)
		{
			last_node->next = NULL;
		}
		return result->next;
	}
};