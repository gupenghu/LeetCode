class Solution {
public:
    int climbStairs(int n) {
        int first = 0,second = 1;
        while(n--){
            second = second + first;
            first = second - first;
        }
        return second;
    }
};