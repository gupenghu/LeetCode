//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
	TreeNode* sortedListToBST(ListNode* head) {
		int sz = 0;
		ListNode* node = head;
		while(node){
			node = node->next;
			sz++;
		}
		if(sz == 0) return NULL;
		node = head;
	   TreeNode* root = RecursionBuild(sz);
	   LDR(root,head);
	   return root;
	}
	
	void LDR(TreeNode* node,ListNode* &list_node){
	    if (node == NULL) return;
		LDR(node->left,list_node);
		node->val = list_node->val;
		list_node = list_node->next;
		LDR(node->right,list_node);
	}
	
	TreeNode* RecursionBuild(int n){
		if (n == 0) return NULL;
		int l_n = n/2;
		int r_n = n - 1 - l_n;
		TreeNode* node = new TreeNode(0);
		node->right= RecursionBuild(l_n);
		node->left= RecursionBuild(r_n);
		return node;
	}
};