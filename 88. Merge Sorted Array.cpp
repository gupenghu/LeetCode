// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
//  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.



// Subscribe to see which companies asked this question.

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int curr = m + n - 1;
		int pos1 = m - 1;
		int pos2 = n - 1;
		while (curr >= 0){
			int max;
			if (pos1 >=0 && pos2 >= 0)
				max = nums1[pos1] > nums2[pos2] ? nums1[pos1--]:nums2[pos2--];
			else if (pos1 >=0)
				max = nums1[pos1--];
			else
				max = nums2[pos2--];
			nums1[curr--]= max;
		}
	}
};