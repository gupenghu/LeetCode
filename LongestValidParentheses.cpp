class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int start = 0,max = 0;
        for(int i = 0; i< s.size();i++){
            if(s[i] == '(' )
                stk.push(i);
            else{
                if(stk.size() == 0){
                    start = i + 1;
                }
                else
                {
                    stk.pop();
                    max = stk.empty() ? (max > i - start + 1 ? max : i-start + 1) : (max > i - stk.top() ? max : i - stk.top());
                }
            }
        }
        return max;
    }
};