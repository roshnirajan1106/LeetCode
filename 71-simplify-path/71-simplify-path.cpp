class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if(path[n-1] != '/')
            path +='/';
        
        n++;
        int i =1;
        stack<string>s;
        string temp = "";
        while(i<n)
        {
            if(path[i] == '/')
            {
                cout<<temp.length()<<endl;
                if(temp.length()==0|| temp == ".")
                {
                    //do nothing
                    cout<<temp.length();
                    
                }
                else if(temp == "..")
                {
                    if(!s.empty()) s.pop();
                }
                else
                    s.push(temp);
                
               
                temp="";
            }
            else
            {
                temp +=path[i];
                cout<<temp<<" ";
                
            }
            ++i;
                
        }
        string ans ="";
        while(!s.empty())
        {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        if(ans.length() == 0)
            return "/";
        return ans;
        
    }
};