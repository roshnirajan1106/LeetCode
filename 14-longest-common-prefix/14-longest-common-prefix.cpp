class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        
        for(int i = 1; i<strs.size();i++)
        {   
            string t="";
            for(int j = 0; j<strs[i].size() && j<temp.length();j++)
            {
                if(temp[j] == strs[i][j])
                    t += temp[j];
                else
                    break;
            }
            
            temp = t;
        }
        return temp;
    }
};