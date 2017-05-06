// Given two binary trees, write a function to check if they are equal or not. 

// Two binary trees are considered equal if they are 
//structurally identical and the nodes have the same value. 



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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        LRR(p,q,same);
        return same;
    }
    void LRR(TreeNode* p, TreeNode* q,bool &same){
    	
    	if (!p != !q)
    	{
    		same = false;
    		return;
    	}
    	if (!same||!p) return;
    	LRR(p->left,q->left,same);
    	if (p->val != q->val)
    	{
    		same = false;
    		return;
    	}
    	LRR(p->right,q->right,same);
    }
};