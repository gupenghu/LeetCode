// Follow up for "Remove Duplicates":
//  What if duplicates are allowed at most twice?

// For example,
//  Given sorted array nums = [1,1,1,2,2,3], 

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 



// Subscribe to see which companies asked this question.

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    if (nums.size() == 0) return 0;
		int i = 0;
		int current = 1;
		int find_times = 1;
		int length = nums.size();
		while(++i < length){
			if (nums[i] == nums[i - 1]){
				find_times++;
				if(find_times > 2) continue;
			}
			else find_times = 1;
			nums[current++] = nums[i];
		}
		return current;
	}
};