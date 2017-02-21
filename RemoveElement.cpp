class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.size() == 0) return 0;
        int number = nums[0],result = 0;
        int j = 0;
        for(int i = 0;i <nums.size();i++){
           if(nums[i] == val) continue;
           nums[j] = nums[i];
           j++;
        }
        if(j !=0 )nums.resize(j);
        return j;
    
    }
};