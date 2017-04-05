// •Total Submissions: 292113

// •Difficulty: Medium
// •Contributors:  Admin  



// Given a collection of integers that might contain duplicates, nums, return all possible subsets. 

// Note: The solution set must not contain duplicate subsets. 

// For example,
//  If nums = [1,2,2], a solution is: 
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]


class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> elem;
		vector<vector<int>> result;
		find_subset(nums,0,elem,result);
		return result;
	}
	
	void find_subset(const vector<int> &nums,int start,vector<int>& elem,vector<vector<int>> &result){
		result.push_back(elem);
		for (int i = start; i < nums.size(); ++i){
			//if (elem.size() > 0 && elem[elem.size() - 1] != nums[start] && start > 0 && nums[start - 1] == nums[start]) continue;
			elem.push_back(nums[i]);
			find_subset(nums,i + 1,elem,result);
			elem.pop_back();
			while (i + 1< nums.size() && nums[i] == nums[i + 1]) ++i;
		}
	}
};