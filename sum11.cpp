class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		find_anwser(candidates, 0, target);
		return result;
	}
	vector<int> anwser;
	vector<vector<int>> result;
	void find_anwser(vector<int>&candidates, int index, int target) {
		for (int i = index; i < candidates.size(); ++i) {
			if (target > candidates[i]) {
				if (i > index && candidates[i] == candidates[i - 1]) continue;
				anwser.push_back(candidates[i]);
				find_anwser(candidates, i + 1, target - candidates[i]);
				anwser.pop_back();
			}
			else if (target == candidates[i]) {
				anwser.push_back(target);
				result.push_back(anwser);
				anwser.pop_back();
			}
			else
				return;
		}

	}

};