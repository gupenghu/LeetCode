// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3



// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3



// Note:
//  Bonus points if you could solve it both recursively and iteratively. 
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
    bool isSymmetric(TreeNode* root) {
        return root ? is_same(root->left,root->right) : true;
    }
    bool is_same(TreeNode*a,TreeNode*b){
    	if (!a != !b) return false;
    	if (!a) return true;
    	if (a->val != b->val) return false;
    	if (!is_same(a->left,b->right)) return false;
    	if (!is_same(a->right,b->left)) return false;
    	return true;
    }
};