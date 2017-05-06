// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
//  Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7



// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> Q;
		queue<TreeNode*> NQ;
		vector<vector<int>> result;
		vector<int> part;
		
		if(root) Q.push(root);
		while(true){
			if (Q.empty()) {
				swap(Q,NQ);
				if(part.size() != 0)result.push_back(part);
				part.clear();
				if (Q.empty()) break;
			}
			TreeNode* node = Q.front();
			part.push_back(node->val);
			if (node->left) NQ.push(node->left);
			if (node->right) NQ.push(node->right);
			Q.pop();
		}
		return result;
	}
};