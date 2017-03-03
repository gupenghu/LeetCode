class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return result;
		}
		int x = 0, y = 0;
		int width = matrix[0].size();
		int height = matrix.size();
		while (width > 0 && height > 0) {
			for (int i = y; i < y + width; ++i)
			{
				result.push_back(matrix[x][i]);
			}

			for (int i = x + 1; i < x + height - 1; ++i)
			{
				result.push_back(matrix[i][y + width - 1]);
			}
			
			if (height > 1) {
				for (int i = y + width - 1; i >= y; i--)
				{
					result.push_back(matrix[x + height - 1][i]);
				}
			}

			if (width > 1) {
				for (int i = x + height - 2; i > x; i--)
				{
					result.push_back(matrix[i][y]);
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