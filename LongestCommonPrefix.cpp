class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		string prfstr = strs[0];
		int index = strs.size() - 1;
		while (index){
		    if (strs[index].size() == 0) return "";
			for (int i = 0; i < strs[index].size() && i < prfstr.size(); i++){
				if (prfstr[i] != strs[index][i]){

					prfstr = prfstr.substr(0, i);
					break;
				}
				if (i == prfstr.size() - 1 || i == strs[index].size() - 1){
					prfstr = prfstr.substr(0, i+1);
					break;
				}
			}
			index--;
		}
		return prfstr;
	}
};