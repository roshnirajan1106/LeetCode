class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0 ; i <flowerbed.size() && n  > 0 ;i++)
        {
            if(flowerbed[i] == 0)
            {
                if( i == 0 )
                {
                    if(flowerbed.size() > 1)
                    {
                        if(flowerbed[i+1] == 0)
                        {
                            n--;
                            flowerbed[i] = 1;
                        }
                        
                        
                    }
                
                    else{
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if( i == flowerbed.size() -1)
                {
                    if(flowerbed.size() > 1)
                    {
                        if(flowerbed[i-1] == 0)
                        {
                            flowerbed[i] = 1;
                            n--;
                            
                        }
                    }
                    else{
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else {
                    if(flowerbed[i-1]== 0 && flowerbed[i+1] == 0)
                    {
                        flowerbed[i]  = 1;
                        n--;
                    }
                }
            }
        }
        return n == 0 ? true : false;
         
    }
};