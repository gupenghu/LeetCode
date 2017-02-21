// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
class Solution {
public:
    bool isMatch(string s, string p) {
    	if (s.size() == 0 && p.size() == 0)
    	{
    		return true;
    	}
        if (p[0] == '*')
        {
        	if (isMatch(s.substr(1),p))
        	{
        		return true;
        	}
        	else if(isMatch(s.substr(1),p.substr(1))){
        		return true;
        	}
        	else
        		return false;
    	}
    	else if (p[0] == '?' || (p[0] == s[0]))
    	{
    		return isMatch(s.substr(1),p.substr(1));
    	}
    	
    	return false;
};