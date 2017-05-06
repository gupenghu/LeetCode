// Given a binary tree, find its maximum depth.Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
	int max;
    int maxDepth(TreeNode* root) {
        max = 0;
        LUR(root,0);
        return max;
    }
    void LUR(TreeNode* node,int depth){
    	if(!node) return;
    	depth = depth + 1;
    	if (depth > max) max = depth;
    	LUR(node->left,depth);
    	LUR(node->right,depth);
    }
};