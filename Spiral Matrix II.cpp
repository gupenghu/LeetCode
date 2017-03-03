class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result;
		for (int i = 0; i < n; ++i)
		{	
			vector<int> temp(n,0);
			result.push_back(temp);
		}
		int x = 0, y = 0;
		int width = n;
		int height = n;
		int integer = 1;
		while (width >= 0 && height >= 0) {
			for (int i = y; i < y + width ; ++i)
			{
				result[x][i] = integer++;
			}

			for (int i = x + 1; i < x + height - 1; ++i)
			{
				result[i][y + width - 1] = integer++;
			}
			if (height > 1) {
				for (int i = y + width - 1; i >= y; i--)
				{
					result[x + height - 1][i] = integer++;
				}
			}
			if (width > 1) {
				for (int i = x + height - 2; i > x; i--)
				{
					result[i][y] = integer++;
				}
			}
			x = x + 1;
			y = y + 1;
			width = width - 2;
			height = height - 2;
		}
		return result;
	}
};