class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int ,int>>res(n);
        res[0].first = 0;
        res[0].second= 2;
        
        int maximum =0;
        for(int i = 1;i<n;i++){
            for(int j = i-1;j>=0;j--)
            {
                int diff = nums[i]-nums[j];
                if(diff == 0)
                    continue;
                //cout<<i<<" "<<j<<" "<<res[j].second<<endl;
                if(res[j].second == 2 && res[i].first < res[j].first + 1)
                {
                    cout<<j<<endl;
                    if(diff > 0)
                    {
                        res[i].first = 1;
                        res[i].second = 1;
                    }
                    else{
                        res[i].first = 1;
                        res[i].second = 0;
                    }
                }
                else if(diff > 0 && res[j].second == 0 && res[i].first < res[j].first + 1)  
                {
                    res[i].first =  res[j].first + 1;
                    res[i].second = 1;

                }
                else if(diff<0 && res[j].second == 1 && res[i].first < res[j].first + 1) {
                    res[i].first =  res[j].first + 1;
                    res[i].second = 0;
                    
                }
                maximum = max(maximum,res[i].first);
            }
         cout<<res[i].first<<" "<<res[i].second<<endl;

            
        }
        return maximum+1;
        
    }
};