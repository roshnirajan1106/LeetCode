class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num = m + n - 1;
        int i = m-1;
        int j =n-1;
        while(i>=0 && j >=0)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[num] = nums2[j];
                j--;
            }
            else{
                nums1[num]  = nums1[i];
                i--;
            }
            num--;
        }
        while(i>=0)
            nums1[num--] = nums1[i--];
        while(j >= 0)
            nums1[num--] = nums2[j--];
    }
};