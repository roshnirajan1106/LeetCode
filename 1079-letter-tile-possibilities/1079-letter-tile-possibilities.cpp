class Solution {
public:
    int dfs(vector<int>&chars)
    {
         int sum = 0;
        for(int i = 0;i<26;i++)
        {
            if(chars[i] == 0)
                continue;
            sum++;
            chars[i]--;
            sum += dfs(chars);
            chars[i]++;
            
        }
 return sum;
    }
    int numTilePossibilities(string tiles) {
        vector<int> characters(26,0);
        for(int i = 0;i<tiles.length();i++)
        {
            char p = tiles[i]-'A';
            characters[p] ++;
        }
        return dfs(characters);
    }
    
};