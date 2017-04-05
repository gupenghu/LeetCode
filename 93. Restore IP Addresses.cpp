// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
//  Given "25525511135", 

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int match_level = 1;
        vector<string> result;
        string match;
        dfs(s,match,match_level,result);
        return result;
    }
    
    void dfs(string s,string match,int match_level,vector<string> &result){
    	if (s.size() == 0) return;
    	if(match_level == 4){
    	    if(s.size() > 1 && s[0] == '0') return;
    		int num = stoi(s);
    		if (num >= 0 && num <= 255){
    			match = match + "." + s;
    			result.push_back(match);
    		}
    		return;
    	}
    	
    	for (int i = 1; i <= 3; ++i){
    		if (s.size() > i && (s.size() - i) <= (4 - match_level) * 3 && (s.size() - i) >= (4 - match_level)){
    			string s1 = s.substr(i);
    			string s2 = s.substr(0,i);
    			int num = stoi(s2);
    			if(s2.size() > 1 && s2[0] == '0') continue;
    			if (num >= 0 && num <= 255){
    				string temp_match = match.size() != 0 ? match + "." + s2 : match +  s2;
    				cout<<match<<endl;
    				dfs(s1,temp_match,match_level + 1,result);
    			}
    		}
    	}
    }
};