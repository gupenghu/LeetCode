// Given a binary tree, determine if it is a valid binary search tree (BST). 

// Assume a BST is defined as follows: 
// •The left subtree of a node contains only nodes with keys less than the node's key.
// •The right subtree of a node contains only nodes with keys greater than the node's key.
// •Both the left and right subtrees must also be binary search trees.


// Example 1:

//     2
//    / \
//   1   3

// Binary tree [2,1,3], return true. 

// Example 2:

//     1
//    / \
//   2   3

// Binary tree [1,2,3], return false. 



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
	int last;
	bool fail;
	bool is_first;
    bool isValidBST(TreeNode* root) {
    	if(!root) return true;
    	is_first = true;
    	fail = false;
        last = root->val;
        LRR(root);
        return !fail;
    }
   
    void LRR(TreeNode* node){
    	if (!node||fail) return;
    	LRR(node->left);
    	if(!is_first && node->val <= last) fail = true;
    	is_first = false;
    	last = node->val;
    	LRR(node->right);
    }
};