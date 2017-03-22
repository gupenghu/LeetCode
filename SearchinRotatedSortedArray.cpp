class Solution {
public:
		int search(vector<int>& nums, int target) {
				int left = 0,right = nums.size() - 1;
				while(left <= right){
						if(right > nums.size() - 1|| left < 0 || left>right) return -1;
						int mid  = left + (right - left)/2;
						if(nums[mid] == target) return mid;
							if(nums[mid] < target){
								if(nums[mid] > nums[left] || target <= nums[right]){
										left = mid + 1;
								}else{
										right = mid - 1;
								}
							}
							if(nums[mid] > target){
									if(target >= nums[left] || nums[mid] < nums[right] ){
										right = mid - 1;
									}else{
										left = mid + 1;
									}
							}
				}
				return -1;
		}
};
