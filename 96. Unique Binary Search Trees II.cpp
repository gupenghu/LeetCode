class Solution {
public:
    int generateTreesNum(int n) {
    	int all = 1;
    	for (int i = n + 1; i <= 2n; ++i)
    	{
    		all = all * i;
    	}
    	
    	int select = 1;
    	
    	for (int i = 1; i <= n; ++i)
    	{
    		select = select * i;
    	}
    	
    	return all/select - (all/n)/(select*(n + 1))
    }
 
	
};