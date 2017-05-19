// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. 
// For example:
//  Given the below binary tree and sum = 22,               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1


// return

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> part;
        LDR(root,sum,part,result);
        return result;
    }
    
     void LDR(TreeNode*node,int sum,vector<int>& part,vector<vector<int>>& result){
    	if(!node) return;
    	part.push_back(node->val);
    	sum = sum - node->val;
    	if (node->right == NULL && node->left == NULL)
    	{
    		if (sum == 0) 
    			result.push_back(part);
    	}
   
    	LDR(node->left,sum,part,result);
    	LDR(node->right,sum,part,result);
    	part.pop_back();
    }
};