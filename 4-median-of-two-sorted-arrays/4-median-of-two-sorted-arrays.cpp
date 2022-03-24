class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        
        int m = nums1.size();
        
        int n = nums2.size();
        int size = (m+n+1)/2;
        int low = 0;
        int high = m;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int l1 = mid;
            int l2 = size-mid;
            int r1 = l1;
            int r2 = l2 ;
            int left1 = (l1 == 0) ? INT_MIN : nums1[l1-1];
            int left2 = (l2 == 0) ? INT_MIN: nums2[l2-1];
            int right1 = (r1 == m) ? INT_MAX : nums1[r1];
            int right2 = (r2 == n) ? INT_MAX : nums2[r2];
            cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<endl;
            if(left1<=right2 && left2 <= right1)
            {
                if(((m+n) % 2) == 1 )
                {
                    return max(left1 ,left2);
                }
                else
                {
                    double ans = (max(left1,left2) + min(right1,right2) )/ 2.0;
                    return ans;
                }
            }
            else if(left1 > right2)
            {
                high= mid-1;
            }
            else{
                low  = mid +1;
            }
            
        
        }
        return 0.0;
        
    }
};