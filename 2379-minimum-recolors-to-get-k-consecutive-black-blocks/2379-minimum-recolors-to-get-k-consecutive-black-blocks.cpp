class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0 ;
        int i =  0;
        int n = blocks.size();
        int j = 0;
        int ans = INT_MAX;
        int flag = 0;
        while( j < n)
        {
            if(blocks[j] == 'B')
                cnt++;
            
            if(j - i + 1 == k  )
            {
                ans = min(ans,max(0,k-cnt));
                
                if(blocks[i] == 'B')
                    cnt--;
                
                i++;
                
                j++;
                flag = 1;
            }
            else if(j - i + 1 < k)
                j++;
            else{
                i++;
            }
        }
        if(flag == 0)
            return -1;
        return ans;
    }
};