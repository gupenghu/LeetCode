class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[256] = {0};
        for(int i = 0; i< 256; i++){
             dict[i] = -1;
        }
        int size = s.size();
        int count = 0;
        int max = 0;
        for(int i = 0; i < size; i++){
            int index = s[i] - 0; 
            int length = i - dict[index] ;
            
            if(count < length)  count ++;
            else    count = length;
            
            max = max > count ? max : count;
            dict[index] =  i;
             
        }
        return max ;
        
    }
};