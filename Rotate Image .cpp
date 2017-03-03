class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j < N - i; ++j)
			{
			    int x = i,y = j;
				int temp =  matrix[N-y-1][x] ;
				matrix[N-y-1][x] = matrix[x][y]	;

				x = N-y-1;
				y = x;
				temp = matrix[N-y-1][x];
				matrix[N-y-1][x] = matrix[x][y];

				x = N-y-1;
				y = x;
				temp = matrix[N-y-1][x];
				matrix[N-y-1][x] = matrix[x][y];
				
				matrix[i][j] = temp;
			}
		}
    }
};