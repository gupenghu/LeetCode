// Given a 2D board and a word, find if the word exists in the grid. 

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. 

// For example,
//  Given board = 
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
	    vector<vector<bool>> occupy(board.size(),vector<bool>(board[0].size(),0));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
			
				if (DFS(board,i,j,word,0,occupy)) return true;
			}
		}
		return false;
	}
	bool DFS(vector<vector<char>>& board,int x,int y,string word,int sz,vector<vector<bool>> &occupy){
	   // cout<<sz<<endl;
		
		
		if (board[x][y] == word[sz])
		{
		    //cout<<x<<" "<<y<<" "<<board[x][y]<<endl;
			occupy[x][y] = true;
			sz++;
			
			if (x > 0 && !occupy[x - 1][y]) 
				if (DFS(board,x - 1,y,word,sz,occupy)) return true;
			if (y > 0 && !occupy[x][y - 1]) 
				if (DFS(board,x,y - 1,word,sz,occupy)) return true;
			if (x + 1< board.size() && !occupy[x + 1][y]) 
				if(DFS(board,x + 1,y,word,sz,occupy)) return true;
			if (y + 1< board[0].size() && !occupy[x][y + 1]) 
				if(DFS(board,x,y + 1,word,sz,occupy)) return true;
			//cout<<"========="<<endl;
			if (sz == word.size())	return true;
			occupy[x][y] = false;
		}
		return false;
	}
};