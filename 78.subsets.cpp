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
    vector<vector<int>> subsetsWith(vector<int>& nums) {
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
        }
    }
};