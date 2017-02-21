// Given an array of non-negative integers, you are initially positioned at the first index of the array. 

// Each element in the array represents your maximum jump length at that position. 

// Your goal is to reach the last index in the minimum number of jumps. 

// For example:
//  Given array A = [2,3,1,1,4] 

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 

// Note:
//  You can assume that you can always reach the last index


class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> step(nums.size(),0);
		for (auto i = nums.begin(); i != nums.end(); ++i)
		{
			for (int j = 1; i < nums[i]; ++j)
			{
				if (step[i + j] == 0 ){
					step[i + j] = step[i] + j;
				}
				else if(step[i + j] > step[i] + j;) {
					step[i + j] = step[i] + j;
				}
			}
		}
		return step[step.size() - 1];
	}
};


ret:目前为止的jump数

curRch:从A[0]进行ret次jump之后达到的最大范围

curMax:从0~i这i+1个A元素中能达到的最大范围

当curRch < i，说明ret次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到

记录的curMax。



class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return ret;
    }
};
