class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN&&divisor == -1) return INT_MAX;
        if(divisor == 0) return 0;
       
       int result = 0;
      
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while(dvd>=dvs){
            long long temp = dvs;
            int i = 1;
            while(dvd >= (temp<<1)){
                temp = temp << 1;
                i = i<<1;
               
            }
            dvd-= temp;
            result+= i; 
        }
      
        return sign == 1?result:-result;
    }
};