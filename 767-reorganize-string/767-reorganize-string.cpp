class Solution {
public:
    string reorganizeString(string s) {
        if(s.length() == 1)
            return s;
        
        map<char,int>m;
        for(auto p : s)
            m[p]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto p : m)
        {
            pq.push({p.second,p.first});
        }
        
        string res = "";
        while(!pq.empty())
        {
            pair<int,char>p =pq.top();
            
          
            int num = p.first;
            char ch = p.second;
            cout<<ch<<" "<<num<<endl;
            pq.pop();
            
            if(res.back() == ch && pq.size())
            {   
                cout<<"heyo ";
                char c = pq.top().second;
                int n = pq.top().first;
                cout<<c<<" "<<n<<endl;
                pq.pop();
                res += c;
                cout<<res<<endl;
                if(n-1 != 0)
                    pq.push({n-1,c});
                
                pq.push({num,ch});
                
            }
            else if(res.back() == ch && !pq.size())
                return "";
            else{
                res += ch;
            num -= 1;
            if(num != 0)
            pq.push({num,ch});
            }
            
        }
        return res;
    }
};