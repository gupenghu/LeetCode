// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:


// •Integers in each row are sorted from left to right.
// •The first integer of each row is greater than the last integer of the previous row.


// For example,

// Consider the following matrix: 
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]


// Given target = 3, return true.

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0 )	return false;
		int col_begin = 0;
		int col_end = matrix.size();
		while(col_begin  + 1 < col_end){
			int col_mid = (col_begin + col_end) / 2;
			if (matrix[col_mid][0] <= target)
			{
				col_begin = col_mid;
			}else{
				col_end = col_mid;
			}
		}
		
		int row_begin = 0;
		int row_end = matrix[0].size();
		while(row_begin  + 1 <  row_end){
			int row_mid = (row_begin + row_end) / 2;
			if (matrix[col_begin][row_mid] <= target)
			{
				row_begin = row_mid;
			}else{
				row_end = row_mid;
			}
		}
		if (matrix[col_begin][row_begin] == target) return true;
		return false;
	}
};