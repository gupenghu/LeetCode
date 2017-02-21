class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0,right = nums.size() - 1,mid = 0;
        while(left <= right){
            mid = left + ((right -left)>>1);
            nums[mid] < target ? left = mid + 1 : right = mid - 1;
        }
      return left;
    }
};