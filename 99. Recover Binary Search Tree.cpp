// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure. 
// Note:
//  A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 



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
	vector<TreeNode*> v_n;
    void recoverTree(TreeNode* root) {
        LRR(root);
        TreeNode* error_node1;
        TreeNode* error_node2;
        for (int i = 0; i + 1 < v_n.size(); ++i){
        	if (v_n[i]->val > v_n[i + 1]->val){
        		error_node1 = v_n[i];
        		break;
        	}
        }
        
        for (int i =  v_n.size() - 1; i >=1; --i){
        	if (v_n[i]->val <= v_n[i - 1]->val){
        		error_node2 = v_n[i];
        		break;
        	}
        }
        
        int temp = error_node1->val;
        error_node1->val = error_node2->val;
        error_node2->val = temp;
    }
    
    void LRR(TreeNode* node){
    	if(!node) return;
    	LRR(node->left);
    	v_n.push_back(node);
    	LRR(node->right);
    }
};