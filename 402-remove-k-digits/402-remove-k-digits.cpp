class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        if(k == num.length())
            return "0";
        for(int i = 0;i<num.length();i++)
        {
            while(k > 0 && !s.empty() && s.top() > num[i])
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        
            
        }
        cout<<s.size()<<endl;
        while(k>0 && !s.empty() )
        {
            s.pop();
            k--;
        }
            
        
        string str = "";
        while(!s.empty())
        {
            str+= s.top();
            s.pop();
        }
        
        reverse(str.begin(),str.end());
        int i = 0;
        cout<<str<<endl;
        while(i < str.length())
        {
            if(str[i] == '0')
                i++;
            else
                break;
        }
        string sub = str.substr(i);
        return sub.length() == 0 ? "0" : sub;
    }
};