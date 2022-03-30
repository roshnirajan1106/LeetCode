class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict;
        map<string,int>m;
        
        for(auto p : wordList)
        {
            dict.insert(p);
            m[p] = INT_MAX;
        }
        vector<vector<string>>res;
        if(dict.find(endWord) == dict.end())
            return res;
        
        
        
        queue<pair<string,vector<string>>>q;
        q.push({beginWord,{beginWord}});
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                string str = top.first;
                vector<string>temp  = top.second;
                
                if(str == endWord)
                {
                    res.push_back(temp);
                    continue;
                }
                
                for(int i = 0;i<str.length();i++)
                {
                    char t= str[i];
                    for(char c = 'a' ;c<='z';c++)
                    {
                        str[i]=c;
                        if(dict.find(str) == dict.end())
                            continue;
                        if(m[str] < temp.size())
                            continue;
                        m[str] = temp.size();
                        temp.push_back(str);
                        
                        q.push({str,temp});
                        temp.pop_back();
                       
                        
                    }
                    str[i] = t;
                }
                
                
            }
        }
        return res;
    }
};