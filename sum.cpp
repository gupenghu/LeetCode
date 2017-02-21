
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		find_anwser(candidates, 0, target);
		return result;
	}
	vector<vector<int>> result;
	vector<int> num_position;
	void find_anwser(vector<int>& candidates, int k, int target) {
		if (target == candidates[k]) {
			vector<int> answer;
			for (int i = 0; i < num_position.size(); ++i) {
				answer.push_back(candidates[num_position[i]]);
			}
			answer.push_back(candidates[k]);
			result.push_back(answer);
			return;
		}

		if (k + 1 < candidates.size() && target - candidates[k] > 0) {
			num_position.push_back(k);
			find_anwser(candidates, k + 1, target - candidates[k]);
			num_position.pop_back();
			find_anwser(candidates, k + 1, target);
		}
	}
};
