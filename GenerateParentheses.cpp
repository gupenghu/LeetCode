class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> result; 
      string str("");
      recursion(result,str,n,0);
      return result;
    }
    void recursion( vector<string> &result ,string str,int left,int right){
        if(left == 0 && right == 0) result.push_back(str);
        if(left > 0) recursion(result,str + "(",left - 1,right + 1);
        if(right > 0) recursion(result,str + ")",left,right - 1);
    }
};