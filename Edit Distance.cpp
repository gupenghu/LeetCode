// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.) 

// You have the following 3 operations permitted on a word: 

// a) Insert a character
//  b) Delete a character
//  c) Replace a character


// i : the length of the target
// j : the length of the source
// D(0, 0) = 0
// D(i, 0) = insertCost * i, means the length of the target is i and the length of the source is 0, so u should insert i characters
// D(0, j) = deleteCost * j, means the length of the target is 0 and the length of the source is j, so u should delete j characters
// D(i, j) = min {D(i - 1, j) + insertCost(target[i]);
// D(i - 1, j - 1) + substituteCost(source[j], target[i]);
// D(i, j - 1) + deleteCost(source[j])} means u should choose the method which will cost least.substituteCost = {0, 2}, if source[j] is equal to target[i], it's 0, or it's 2.

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> data(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i < word1.size() + 1; ++i) data[i][0] = i;
		for (int i = 0; i < word2.size() + 1; ++i) data[0][i] = i;
		for (int i = 1; i < word1.size() + 1; ++i)
		{
			for (int j = 1; j < word2.size() + 1; ++j)
			{
				if (word1[i - 1] == word2[j - 1])	data[i][j] = data[i - 1][j - 1];
				else	data[i][j] = min(data[i - 1][j - 1] + 1, min(data[i][j - 1] + 1, data[i - 1][j] + 1));
			}
		}
		return data[word1.size()][word2.size()];
	}
};
