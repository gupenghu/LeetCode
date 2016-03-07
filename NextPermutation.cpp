class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() == 0) return;
        bool found = 0;
        int p1 = 0,p2;
        for(p1  = nums.size() - 1; p1 > 0; p1--){
            if(nums[p1] > nums[p1-1])  {
                found = 1;
                break;
            }
        }
        p2 = p1;
        for(int i = nums.size() - 1; i >= p1;i--){
                if(nums[i] > nums[p1-1]) {
                    p2 = i;
                    break;
                }
        }
        if(found) {
            swap(nums[p1-1],nums[p2]);
            reverse(nums.begin()+ p1,nums.end());
        }else{
            reverse(nums.begin(),nums.end());
        }
        
    }
};