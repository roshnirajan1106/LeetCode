class Solution {
public:
    bool is_possible(map<int,int> &m, vector<int> arr, int num)
    {
        int diff = num - 5;
        m[num] ++;
        if(diff == 0)
            return true;
        
            int i = 2;
            while(i >=0 && diff > 0){
                
                if(arr[i] <= diff && m.find(arr[i]) != m.end() && m[arr[i]] != 0)
                {
                    diff -= arr[i];
                    m[arr[i]]--;
                }
                else{
                    i--;
                }
                    
            }
        if(diff > 0)
            return false;
        return true;
        
        
    }
    bool lemonadeChange(vector<int>& bills) {
        vector<int> arr = {5,10,20};
        map<int,int> m;
        for(int i = 0; i< bills.size();i++)
        {
            bool check  =  is_possible(m,arr,bills[i]);
            if(check  == false)
                return false;
        }
        return true;
        
    }
};