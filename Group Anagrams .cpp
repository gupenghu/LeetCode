
// Given an array of strings, group anagrams together. 

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
//  Return: 
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> result;
    	map<string,int> assist;
        for (int i = 0; i < strs.size(); ++i)
        {
        	string temp = strs[i];
        	sort(temp);
        	if (assist.find(temp)){
        		result[assist[temp]].pusk_back(strs[i])
        	}
        	else{
        		vector<string> vs;
        		vs.push_back(temp);
        		result.pusk_back(vs);
        		assist[temp] = result.size() - 1;
        	}
        }
        retunr result;
    }
};