// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?




// Above is a 3 x 7 grid. How many possible unique paths are there? 

// Note: m and n will be at most 100.


class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n)
		{
			int temp = m;
			m = n;
			n = temp;
		}
		m = m - 1;
		n = n - 1;
		long low = 1;
		for (int i = 1; i <= m; ++i)
		{
			low = i * low;
		}
		
		long high = 1;
		for (int i = n + 1; i <= m + n; ++i)
		{
			high = high * i;
		}
		
		return high/low;
	}
};