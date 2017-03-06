

// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,


// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
		{
			return 0;
		}
		int result = 0;
		if (obstacleGrid[0][0] != 1)
		{
			find_way(obstacleGrid,0,0,result);
		}
		return result;
	}
	
	void find_way(vector<vector<int>>& obstacleGrid,int m,int n,int &result){
		if (m == obstacleGrid.size() - 1 && n == obstacleGrid[0].size() - 1 && obstacleGrid[m][n] != 1)
		{
			result++;
			return;
		}
		if (n + 1 < obstacleGrid[0].size() && obstacleGrid[m][n + 1] != 1)
		{
			find_way(obstacleGrid,m,n + 1,result);
		}
		if (m + 1 < obstacleGrid.size() && obstacleGrid[m + 1][n] != 1)
		{
			find_way(obstacleGrid,m + 1,n,result);
		}
	}
};


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1 || 
			obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
		{
			return 0;
		}
		int height = obstacleGrid.size();
		int width = obstacleGrid[0].size();
		vector<vector<int>> assis_array(height,vector<int>(width,0));		
		assis_array[0][0] = 1;
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (i == 0 && j == 0) continue;
				if(obstacleGrid[i][j] == 1) continue;
				int left = 0;
				int up = 0;
				if (j > 0)
				{
					left = assis_array[i][j - 1];
				}
				if (i > 0)
				{
					up = assis_array[i - 1][j];
				}
				assis_array[i][j] = left + up;
			}
		}
		return assis_array[height - 1][width - 1];
	}
};