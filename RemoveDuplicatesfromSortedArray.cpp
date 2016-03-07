class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int number = nums[0],result = 0;
        int j = 0;
        for(int i = 1;i <nums.size();i++){
           if(nums[i] == nums[j]) continue;
           nums[++j] = nums[i];
        }
        nums.resize(++j);
        return j;
    }
};