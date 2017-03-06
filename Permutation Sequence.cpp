// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
//  We get the following sequence (ie, for n = 3): 
// 1."123"
// 2."132"
// 3."213"
// 4."231"
// 5."312"
// 6."321"


// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.


class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums;
		for (int i = 1; i <= n; ++i)
		{
			nums.push_back(i);
		}
		
		for (int i = 2; i <= k; ++i)
		{
			nextPermutation(nums);
		}
		string str;
		for (int i = 0; i < nums.size(); ++i)
		{
			str.push_back(nums[i] + '0');
		}
		return str;
	}
	
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