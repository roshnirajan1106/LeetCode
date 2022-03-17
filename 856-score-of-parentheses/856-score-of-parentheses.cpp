class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>str;
        str.push(0);
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                str.push(0);
            }
            else{
                int top = str.top();
                str.pop();
                int val ;
                if(top == 0)
                {
                 val = 1;
                }
                else{
                    val = top*2;
                }
                    
                str.top() += val;
            }
        }
        return str.top();
    }
};