// Reverse a linked list from position m to n. Do it in-place and in one-pass. 

// For example:
//  Given 1->2->3->4->5->NULL, m = 2 and n = 4, 

// return 1->4->3->2->5->NULL. 

// Note:
//  Given m, n satisfy the following condition:
//  1 ≤ m ≤ n ≤ length of list. 
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode* ret = new ListNode(0);
		ret->next = head;
		ListNode* m_pos= ret;
		ListNode* n_pos= ret;
		while(--m) m_pos = m_pos->next;
		while(--n) n_pos = n_pos->next;
		ListNode* begin = m_pos;
		m_pos = m_pos->next;
		ListNode* end = n_pos->next;
		ListNode* end_next = end->next;
		ListNode* last = end->next;
		while(m_pos != end_next){
			ListNode* temp = m_pos;
			m_pos = m_pos->next;
			temp->next = last;
			last = temp;
		}
		begin->next = end;
		return ret->next;
	}
};