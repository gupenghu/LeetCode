// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
//  You may assume that duplicates do not exist in the tree. 

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 if (preorder.size() == 0) return NULL;
		 int pos = 0;
		 return RecursionBuild(preorder,pos,inorder,inorder.begin(),inorder.end());
	}
	
	TreeNode* RecursionBuild(vector<int>& preorder,int &pos,vector<int>& inorder,vector<int>::iterator first,vector<int>::iterator second){
		if (pos >= preorder.size() )return NULL;
		auto iter = find(first,second,preorder[pos]);
		if (iter == second) return NULL;
		TreeNode* node = new TreeNode(preorder[pos]);
		pos = pos + 1;
		node->left= RecursionBuild(preorder,pos,inorder,first,iter);
		node->right= RecursionBuild(preorder,pos,inorder,iter + 1,second);
		return node;
	}
};

