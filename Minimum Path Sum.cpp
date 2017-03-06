// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
		int width = grid[0].size();
		vector<vector<int>> assis_array(height,vector<int>(width,0));
		assis_array[0][0] = grid[0][0];
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				int min;
				if (i ==  0 && j == 0) continue;
				else if (i == 0) min = assis_array[i][j - 1];
				else if (j == 0) min = assis_array[i - 1][j];
				else			 min = assis_array[i][j - 1]< assis_array[i - 1][j] ? assis_array[i][j - 1] : assis_array[i - 1][j];
				
				
				assis_array[i][j] = grid[i][j] + min;
			}
		}
		return assis_array[height - 1][width - 1]; 
    }
};