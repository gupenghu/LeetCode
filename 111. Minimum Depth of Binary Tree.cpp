// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.



// Subscribe to see which companies asked this question.
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
	int min_height;
	int minDepth(TreeNode* root) {
		if(!root) return 0;
		min_height = 0;
		LDR(root,0);
		return min_height;
	}
	void LDR(TreeNode*node,int height){
		if (!node) return;
		height = height + 1;
		if (node->right == NULL && node->left == NULL)
		{
			if(min_height) min_height = min_height < height ? min_height:height;
			else min_height = height;
		}
		LDR(node->left,height);
		LDR(node->right,height);
	}
};