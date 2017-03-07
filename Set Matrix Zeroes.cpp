// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 

// click to show follow up.

// Follow up: 
// Did you use extra space?
//  A straight forward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//  Could you devise a constant space solution? 
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool row = false,col = false;
		for (int i = 0; i < matrix[0].size(); ++i)
		{
			if (matrix[0][i] == 0)
			{
				row = true;
				break;
			}
		}
		
		for (int i = 0; i < matrix.size(); ++i)
		{
			if (matrix[i][0] == 0)
			{
				col = true;
				break;
			}
		}
		
		for (int i = 0; i < matrix.size(); ++i)
		{
				for (int j = 0; j < matrix[0].size(); ++j){
					if (matrix[i][j] == 0)
					{
						matrix[i][0] = 0;
						matrix[0][j] = 0;
					}
				}
		}		
		for (int i = matrix.size() - 1; i >= 1; i--)
		{
			if (matrix[i][0] == 0)
			{
				for (int j = 0; j < matrix[0].size(); ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		
		for (int j = matrix[0].size() - 1; j >= 1; j--)
		{
			if (matrix[0][j] == 0)
			{
				for (int i = 0; i < matrix.size(); ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}
		
		if (row)
		{
			for (int i = 0; i < matrix[0].size(); ++i)
			{
				matrix[0][i] = 0;
			}
		}
		
		if (col)
		{
			for (int i = 0; i < matrix.size(); ++i)
			{
				matrix[i][0] = 0;
			}
		}
	}
};