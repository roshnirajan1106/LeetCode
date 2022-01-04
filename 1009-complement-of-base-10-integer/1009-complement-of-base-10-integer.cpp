class Solution {
public:
    int bitwiseComplement(int n) {
        if( n == 0)
            return 1;
        int temp = n;
        int x =0;
        while(temp >0)
        {
             x = temp & -temp;
            temp = temp -x;

        }
        //cout<<x<<endl;
        x=x-1;
        //cout<<x<<endl;
        x= x<<1;
        //cout<<x<<endl;
        x = x + 1;
        
        //cout<<num<<endl;
        return x ^ n;
            
    }
};