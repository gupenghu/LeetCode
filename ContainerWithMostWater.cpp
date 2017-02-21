class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int capacity = 0;
        int start = 0,end = height.size() - 1;
        while(start < end){
            if(height[start] <= height[end]){
                capacity = (end - start) * height[start];
                result = result > capacity ? result : capacity;
				start++;
            }
            else{
                capacity = (end - start) * height[end];
				result = result > capacity ? result : capacity;
				end--;
            }  
        }
		return result;
    }
};