class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid = -1;
        int s = 0;
        int e = nums.size()-1;
        if(nums.size() == 0)
        {
            vector<int>ans;
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int c = -1;
        while(s <=e )
        {
        
             mid  = s + (e-s)/2;
            //cout<<mid<<endl;
            if(nums[mid] == target)
            {
              //  cout<<mid<<endl;
                c = 1;
                break;
                    
            }
            else if(nums[mid] < target)
            {
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            
        }
        if(c == -1)
        {
            vector<int>ans;
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        cout<<"heyyyy";
        cout<<mid<<endl;
        vector<int>ans;
         s = mid;
        while(s > 0 && nums[s-1] == nums[s] )s--;
         e = mid;
        while(e < nums.size()-1 && nums[e] == nums[e+1])e++;
        ans.push_back(s);
        ans.push_back(e);
        return ans;
    
    }
};