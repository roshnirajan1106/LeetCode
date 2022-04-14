class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        int cnt = nums.size() / 3 ;
        cout<<cnt<<endl;
        int c =1;
        for(int i  =1;i<nums.size();i++)
        {
            if(nums[i-1] == nums[i])
                c++;
            else 
            {
                if(c > cnt)
                    arr.push_back(nums[i-1]);
                c = 1;

            }
        }
        if(c > cnt)
            arr.push_back(nums[nums.size()-1]);
        
        return arr;
        
    }
};