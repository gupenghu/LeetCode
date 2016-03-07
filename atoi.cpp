class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        bool pos = 1;
        while(str[i] == ' '){
            i++;
        }
        
        if(str[i] == '-'){
           pos = 0;
           i++;
            if(str[i]>'9' ||str[i] < '0') return 0;
        }
        if(str[i] == '+'){
           i++; 
            if(str[i]>'9' ||str[i] < '0') return 0;
        } 
        vector<int> s;
        int size = str.size();
        int result = 0;
        while(i < size ){
            if(str[i]>'9' ||str[i] < '0') {
                i++;
                break;
            }
            if(pos == 1){
                if(result > (str[i] - '0' + result * 10)/10) 
					return INT_MAX;
                result = str[i] - '0' + result * 10;
				s.push_back(result);
            }
            else{
                if(result < (0 - (str[i] - '0') + result * 10)/10) return INT_MIN;
                result =  0 - (str[i] - '0') + result * 10;
            }
            i++;
        }
       return result;
    }
};