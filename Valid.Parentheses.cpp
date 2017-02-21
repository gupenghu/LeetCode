class Solution {
public:
    bool isValid(string s) {
        if(!s.size()) return true;
        stack<char> c;
        
        for(int i = 0;i<s.size();i++){
            if(c.empty()){
                c.push(s[i]);
                
            }else{
                if((c.top() == '(' && s[i] == ')') || (c.top() == '[' && s[i] == ']')||(c.top() == '{' && s[i] == '}'))
                    c.pop();
                else c.push(s[i]);
            }
        }
        if(c.empty()) return true;
        return false;
    }
};