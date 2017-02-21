// Given an unsorted integer array, find the first missing positive integer. 

// For example,
//  Given [1,2,0] return 3,
//  and [3,4,-1,1] return 2. 

// Your algorithm should run in O(n) time and uses constant space. 



class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i = 0;
		int value;
		while (i < nums.size()) {
			value = nums[i];
			if ((value < 1 || value >= nums.size()) || value == i + 1 || nums[i] == nums[value - 1]) {
				i++;
			}
			else {
				swap(nums[i], nums[value - 1]);
			}
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (i != nums[i] - 1) {
				return i + 1;
			}
		}
		return nums.size() + 1;
	}
};