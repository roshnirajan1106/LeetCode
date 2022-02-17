class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string str = "";
        while(a >0 && b > 0)
        {
            if(a > b)
            {
                str += "aab";
                a--;
            }
            else if(a < b)
            {
                str += "bba";
                b--;
            }
            else{
                str += "ab";
            }
            a--;
            b--;
        }
        while(a > 0)
        {
            str += 'a';
            a--;
        }
        while(b > 0)
        {
            str += 'b';
            b--;
        }
        return str;
    }
};