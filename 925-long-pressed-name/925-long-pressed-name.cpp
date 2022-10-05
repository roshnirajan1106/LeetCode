class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        int i = 0;
        while(i<name.length())
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            if(name[i] != typed[j])
            {
                while(i > 0 && name[i-1] == typed[j])
                    j++;
                
                if(name[i] != typed[j])
                    return false;
                    
            }
                
        }
        return true;
    }
};