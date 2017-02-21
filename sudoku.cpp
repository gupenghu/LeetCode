class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool col[9][9] = {0};
		bool row[9][9] = {0};
		bool block[9][9] = {0};
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if(board[i][j] == '.') {
					continue;
				}
				else {
					int num = board[i][j] - '0';
					if (col[j][num - 1]  == 1 || row[i][num - 1] == 1 || block[(i/3) * 3 + j/3][num - 1] == 1){
						return false;
					}
					col[j][num - 1] = 1;
					row[i][num - 1] = 1;
					block[(i/3) * 3 + j/3][num - 1] = 1;
				}
			}
		}
		return true;
	}
};
