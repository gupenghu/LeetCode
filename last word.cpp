class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0)
		{
			return 0;
		}
		int flag = s.size() - 1;
		while(flag >= 0){
			if (s[flag] != ' ')
			{
				break;
			}else{
				flag--;
			}
		}
		for (int i = flag; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				return flag - i;
			}
			if (i == 0)
			{
				return flag - i + 1;
			}
			
		}
		return 0;
	}
};