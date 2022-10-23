class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int ptr = 0;
        int i =0;
        while(i < nums.size())
        {
            if(ptr == 0)
            {
                element = nums[i];
                ptr = 1;
                i++;
                continue;
            }
            //check
            if(nums[i] == element)
            {
                ptr++;
            }
            else
            {
                ptr--;
            }
            i++;
                
            
        }
        return element;
    }
};
 