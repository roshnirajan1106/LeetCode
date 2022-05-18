class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int high = m + n - 1;
        int h1 = m-1;
        int h2 = n-1;
        while(h1 >= 0  && h2 >= 0)
        {
            if(nums1[h1] >nums2[h2])
            {
                nums1[high--] = nums1[h1];
                h1--;
            }
            else
            {
                nums1[high--] = nums2[h2];
                h2--;
            }
        }
        while(h1>=0)
            nums1[high--] = nums1[h1--];
        while(h2 >= 0)
            nums1[high--] = nums2[h2--];
        
        
        
    }
};