class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '[' ||s[i] == '{')
            {
                stack.push(s[i]);
            }
            else{
                if(s[i] == ')')
                {
                    if(stack.size() && stack.top()== '(')
                        stack.pop();
                    else
                        return false;
                }
                 if(s[i] == ']')
                {
                    if(stack.size() &&stack.top()== '[')
                        stack.pop();
                    else
                        return false;
                }
                 if(s[i] == '}')
                {
                    if(stack.size() && stack.top()== '{')
                        stack.pop();
                    else
                        return false;
                }
                
        
                    
            }
        }
        if(stack.size() > 0)
            return false;
        return true;
    }
};