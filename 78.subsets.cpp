// •Total Accepted: 146608
// •Total Submissions: 387131
// •Difficulty: Medium
// •Contributors:  Admin  



// Given a set of distinct integers, nums, return all possible subsets. 

// Note: The solution set must not contain duplicate subsets. 

// For example,
//  If nums = [1,2,3], a solution is: 
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> elem;
        vector<vector<int>> result;
        for(int i = 0; i <= nums.size();i++){
        	find_subset(nums,0,elem,i,result);
        }
        return result;
    }
    
    void find_subset(const vector<int> &nums,int start,vector<int>& elem,int n,vector<vector<int>> &result){
    	if(n == 0) result.push_back(elem);
    	for (int i = start; i < nums.size(); ++i){
    		elem.push_back(nums[i]);
    		find_subset(nums,i + 1,elem,n - 1,result);
    		elem.pop_back();
    	}
    }
};