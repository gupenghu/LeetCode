// Given inorder and postorder traversal of a tree, construct the binary tree.

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
   	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		 if (inorder.size() == 0) return NULL;
		 int pos = postorder.size() -1;
		 return RecursionBuild(postorder,pos,inorder.begin(),inorder.end());
	}
	
	TreeNode* RecursionBuild(vector<int>& postorder,int &pos,vector<int>::iterator first,vector<int>::iterator second){
		if (pos < 0 )return NULL;
		auto iter = find(first,second,postorder[pos]);
		if (iter == second) return NULL;
		TreeNode* node = new TreeNode(postorder[pos]);
		pos = pos - 1;
		node->right= RecursionBuild(postorder,pos,iter + 1,second);
		node->left= RecursionBuild(postorder,pos,first,iter);
		return node;
	}
};