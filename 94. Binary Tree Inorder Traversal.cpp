// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
//  Given binary tree [1,null,2,3],

//    1
//     \
//      2
//     /
//    3

// 问题大意是用S表示入栈，X表示出栈，那么合法的序列有多少个(S的个数为n)。

// 显然有c(2n, n)个含S，X各n个的序列，剩下的是计算不允许的序列数(它包含正确个数的S和X，但是违背其它条件)。

// 在任何不允许的序列中，定出使得X的个数超过S的个数的第一个X的位置。然后在导致并包括这个X的部分序列中，以S代替所有的X并以X代表所有的S。结果是一个有(n+1)个S和(n-1)个X的序列。反过来，对一垢一种类型的每个序列，我们都能逆转这个过程，而且找出导致它的前一种类型的不允许序列。例如XXSXSSSXXSSS必然来自SSXSXXXXXSSS。这个对应说明，不允许的序列的个数是c(2n, n-1)，因此an = c(2n, n) - c(2n, n-1)。


// return [1,3,2].

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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorder(root,result);
		return result;
	}
	
	void inorder(TreeNode* node, vector<int> &result){
		if(node == NULL) return;
		inorder(node->left,result);
		result.push_back(node->val);
		inorder(node->right,result);
	}
};