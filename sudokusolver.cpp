class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		fillnext(board);
	}

	int getNextToFill(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					return i * 9 + j;
				}
			}
		}
		return -1;
	}

	bool fillnext(vector<vector<char>>& board) {
		int postion = getNextToFill(board);
		if (postion == -1) {
			return true;
		}
		int x, y;
		x = postion / 9;
		y = postion % 9;

		bool canfill[9] = { 0 };
		for (int i = 0; i < 9; ++i) {
			canfill[i] = true;
		}
		for (int i = 0; i < 9; ++i) {
			if (board[x][i] != '.') {
				canfill[board[x][i] - '0' - 1] = false;
			}

			if (board[i][y] != '.') {
				canfill[board[i][y] - '0' - 1] = false;
			}
		}


		int m = x/3 * 3;
		int n = y/3 * 3;
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (board[i + m][j + n] != '.') {
					canfill[board[i + m][j + n] - '0' - 1] = false;
				}
			}
		}


		for (int i = 0; i < 9; ++i) {
			if (canfill[i] == true) {
				board[x][y] = '0' + i + 1;
				if (!fillnext(board)) {
					canfill[i] = false;

				}
				else
					return true;
			}
		}
		board[x][y] = '.';
		return false;
	}
};