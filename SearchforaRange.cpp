class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1;
        bool found = false;
        vector<int> res = {-1,-1};
        int mid = 0;
        while(left <= right){
             mid = left + (right - left)/2;
            if(nums[mid] == target){
                found = true;
                break;
            }
            else if(nums[mid] > target) right = mid -1;
            else left = mid + 1;
        }
        if(!found) return res;
       // res.push_back(mid);
        left = mid;
        right = mid;
        while(left > 0 && nums[left - 1] == nums[mid]) left--;
        while(right < nums.size() - 1 && nums[right + 1] == nums[mid]) right++;    
        res[0] = left ;
        res[1] = right ;
        return res;
    }
};