class Solution {
public:
    bool detectCapitalUse(string word) {
        int number_of_capitals =0;
        for(int i = 0; i<word.length();i++)
        {
            char ch = word[i];
            if(ch >=65 && ch <=90)
                number_of_capitals++;
        }
        if(number_of_capitals == 1 && (word[0] >= 65 && word[0] <=90))
            return true;
        if(number_of_capitals == 0)
            return true;
        if(number_of_capitals == word.length())
            return true;
        
        return false;
    }
};