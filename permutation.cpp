#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums);
		vector<vector<int>> set;
		find_all_comb(nums, 0, set);
		return set;
	}


	void find_all_comb(vector<int>& nums, int begin, vector<vector<int>> &set) {
		if (begin == nums.size() - 1){
			set.push_back(nums);
		}

		for (size_t i = begin; i < nums.size(); i++)
		{
			if (i + 1 < nums.size() && nums[i] == nums[i + 1])
			{
				continue;
			}
			swap(nums[begin],nums[i]);
			find_all_comb(nums, begin + 1,  set);
			swap(nums[begin], nums[i]);
		}
	}

	//void find_all_comb(vector<int>& nums, vector<bool> &used, vector<int> &found, vector<vector<int>> &set) {
	//	if (found.size() == nums.size())
	//	{
	//		set.push_back(found);
	//		return;
	//	}
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (used[i] == true)
	//		{
	//			continue;
	//		}
	//		used[i] = true;
	//		found.push_back(nums[i]);
	//		find_all_comb(nums, used, found,set);
	//		found.pop_back();
	//		used[i] = false;
	//	}
	//}
};


int main()
{
	Solution s;
	vector<int> source = { 1,2,3 ,4,5};
	vector<vector<int>> set  = s.permute(source);
	for (size_t i = 0; i < set.size(); i++)
	{
		for (size_t j = 0; j < set[i].size(); j++)
		{
			cout << set[i][j];
		}
		cout << endl;
	}
	return 0;

}