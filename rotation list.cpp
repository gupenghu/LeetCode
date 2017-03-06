
// Given a list, rotate the list to the right by k places, where k is non-negative.

// For example:
//  Given 1->2->3->4->5->NULL and k = 2,
//  return 4->5->1->2->3->NULL.



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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
		{
			return head;
		}
		int sz = 1;
		ListNode* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
			sz++;
		}
		k = k%sz;
		ListNode* first = head;
		ListNode* second = head;
		while(k--){
			first = first->next;
		}
		while(first->next != NULL){
			first = first->next;
			second = second->next;
		}
		if (first != second)
		{	
			ListNode* result = second->next;
			second->next = NULL;
			first->next = head;
			head = result;
		}
		
		return head;
	}
};