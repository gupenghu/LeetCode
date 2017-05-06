// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
//  Given n = 3, your program should return all 5 unique BST's shown below. 
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3





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
    vector<TreeNode*> generateTrees(int n) {
    
    }
   for (int i = 0; i < n; ++i)
   {
   		
   }
	
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
       return createTree(1,n);
    }
    
    vector<TreeNode *> createTree(int start, int end)
    {
        vector<TreeNode *> results;
        if(start>end)
        {
            results.push_back(NULL);
            return results;
        }
        
        for(int k=start;k<=end;k++)
        {
            vector<TreeNode *> left = createTree(start,k-1);
            vector<TreeNode *> right = createTree(k+1,end);
            for(int i=0;i<left.size();i++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode * root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};


class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
       return createTree(1,n);
    }
    
     
    
    vector<TreeNode *> createTree(int start, int end){
    	vector<TreeNode *> results;
        if(start>end)
        {
            results.push_back(NULL);
            return results;
        }
        
        for(int k=start;k<=end;k++)
        {
            vector<TreeNode *> left = createTree(start,k-1);// all types of left tree 
            vector<TreeNode *> right = createTree(k+1,end);// all types of right tree
            for(int i=0;i<left.size();i++)   //caculate all types 
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode * root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};