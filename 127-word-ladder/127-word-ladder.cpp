class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict (wordList.begin(), wordList.end());
        int cnt = 0;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string top = q.front();
                q.pop();
                dict.erase(top);
                if(top == endWord)
                    return cnt + 1;
                char ch;
                for(int i = 0; i<top.length();i++)
                {
                    ch = top[i];
                    for(char c='a' ;c<='z';c++)
                    {
                        top[i] = c;
                        if(dict.find(top) != dict.end())
                            q.push(top);
                    }
                    top[i]=ch;
                }
            }
            cnt++;
        }
        return 0;
    }
};