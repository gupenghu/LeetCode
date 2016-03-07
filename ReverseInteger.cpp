class Solution {
public:
    int reverse(int x) {
        bool sym = true;
        if (x == -2147483648) return 0;
        if(x < 0) {
            x = -x;
            sym = false;
        }
        long num = x;
        vector<int> s;
        while(x!=0){
            s.push_back(x%10);
            x = x/10;
        }
        long long result = 0;
        for(int i = 0; i< s.size();i++){
            result = s[i] + result * 10;
        }
        if(sym == false){
            if(result<=2147483648)
            return 0 - result;
            
        }else{
            if(result <= 2147483648-1 ){
            
            return result;
             }
        }
        return 0;
    }
};