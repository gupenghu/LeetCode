//Given an array where elements are sorted in ascending order, 
//convert it to a height balanced BST.


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
		int pos = 0;
		return RecursionBuild(nums.begin(),nums.end()); 
    }
    
    TreeNode* RecursionBuild(vector<int>::iterator first,vector<int>::iterator second){
		if (first == second) return NULL;
		auto mid = first + (second - first)/2;
		if (mid == second) return NULL;
		TreeNode* node = new TreeNode(*mid);
		node->left= RecursionBuild(first,mid);
		node->right= RecursionBuild(mid + 1,second);
		return node;
	}
};


	