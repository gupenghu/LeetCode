// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 

// For example,
//  If n = 4 and k = 2, a solution is: 
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> source;
		for (int i = 0; i < n; ++i) source.push_back(i + 1);
		vector<int> dest;
		vector<vector<int>> result;
		allcombine(source,0,k,dest,result);
		return result;
		
	}
	void allcombine(vector<int> source,int m,int n,vector<int> &dest,vector<vector<int>> &result){
		if (n == 0)
		{
			result.push_back(dest);
		}
		for (int i = m; i < source.size(); ++i)
		{
			dest.push_back(source[i]);
			allcombine(source,i + 1,n - 1,dest,result);
			dest.pop_back();
		}
	}
};
