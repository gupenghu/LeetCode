// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 

// You should preserve the original relative order of the nodes in each of the two partitions. 

// For example,
//  Given 1->4->3->2->5->2 and x = 3,
//  return 1->2->2->4->3->5. 
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
	ListNode* partition(ListNode* head, int x) {
		ListNode* current = head;
		ListNode* sm = new ListNode(0);
		
		ListNode* sm_tail = sm;
		ListNode* bg = new ListNode(0);
		ListNode* bg_tail = bg;
		while(current){
			if (current->val < x)
			{
				sm_tail->next = current;
				sm_tail = current;
			}else{
				bg_tail->next = current;
				bg_tail = current;
			}
			
			current = current->next;
		}
		sm_tail->next = bg->next;
		bg_tail->next = NULL;
		return sm->next;
	}
};
 
// class Solution {
// public:
// 	ListNode* partition(ListNode* head, int x) {
// 		ListNode* current = head;
// 		ListNode* less = new ListNode(0);
// 		less->next = head;
// 		while(current){
// 			if (current->val < x)
// 			{
// 				int temp = less->next->val;
// 				less->next->val = current->val;
// 				current->val = temp;
// 				less = less->next;
// 			}
			
// 			current = current->next;
// 		}
// 		return head;
// 	}
// };

// Input: [2,3,1]
// 2
// Output: [1,3,2]
// Expected: [1,2,3]
// Stdout: 2 1