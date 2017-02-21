
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)  return 0;
		int max_index = 0;
		int max = -1;
		
		for (int i = 0; i < height.size(); ++i)
		{
			if (height[i] > max)
			{
				max = height[i];
				max_index = i;
			}
		}
		
		root = height[0];
		int area = 0;
		for (int i = 0; i < max_index; ++i)
		{
			if(root > height[i]){
				area += root - height[i];
			}else{
				root = height[i];
			}
		}
		root = height[height.size() - 1];
		for (int i = height.size() - 1; i > max_index; i--)
		{
			if(root > height[i]){
				area += root - height[i];
			}else{
				root = height[i];
			}
		}
		return area;
	}
};
