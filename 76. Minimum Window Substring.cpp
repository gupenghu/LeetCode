// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n). 

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"


// Minimum window is "BANC". 

// Note:
//  If there is no such window in S that covers all characters in T, return the empty string "". 

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 



// Subscribe to see which companies asked this question.

class Solution {
public:
	string minWindow(string s, string t) {
		int tv[256] = {0};
		for (int i = 0; i < t.size(); ++i) tv[t[i]]++;
		
		int sv[256] = {0};
		int count = 0;
		int left = 0;
		string result = "";
		int min_len = s.size() + 1;
		for (int i = 0; i < s.size(); ++i)
		{
			if (tv[s[i]]) {
				sv[s[i]]++;
				if (sv[s[i]] <= tv[s[i]]) count++;
			}
			while(count == t.size()){
				if (i - left < min_len)
				{
					min_len = i - left + 1;
					result = s.substr(left,min_len);
				}
				if (tv[s[left]] != 0)
				{
					--sv[s[left]];
					if(sv[s[left]] < tv[s[left]]) --count;
				}
				++left;
			}
		}
		return result;
	}
};