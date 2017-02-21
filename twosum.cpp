class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int size = numbers.size();
		unordered_multimap<int, int> m;
		for (int i = 0; i<size; i++){
			m.insert(make_pair(numbers[i], i));
		}
		vector<int> v;
		int des;
		for (int j = 0; j<size; j++){
			des = target - numbers[j];
			if (m.count(des)){
				auto index = m.find(des);
				int k = index->second;
				if (k>j) {
					v.push_back(j + 1);
					v.push_back(k + 1);
					return v;
				}
			}
		}
		return v;
	}
};