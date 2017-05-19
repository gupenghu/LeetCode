// Given a binary tree and a sum, determine if the tree has a 
//root-to-leaf path such that adding up all the values along the path 
//equals the given sum. 
// For example:
//  Given the below binary tree and sum = 22,              
//				 5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1


// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


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
	bool has;
    bool hasPathSum(TreeNode* root, int sum) {
    	if (!root) return false;
        has = false;
        LDR(root,sum);
        return has;
    }
    
    void LDR(TreeNode*node,int sum){
    	if(!node) return;
    	sum = sum - node->val;
    	if (node->right == NULL && node->left == NULL)
    	{
    		if (sum == 0) has = true;
    		return;
    	}
   
    	LDR(node->left,sum);
    	LDR(node->right,sum);
    }
};