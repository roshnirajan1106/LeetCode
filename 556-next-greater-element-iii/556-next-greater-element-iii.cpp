class Solution {
public:
    int nextGreaterElement(int n) {
         vector<int> digits;
        // extracting digits
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
      
        for (int i = 1, j, len = digits.size(), lmt = INT_MAX / 10; i < len; i++) {
            if (digits[i - 1] > digits[i]) {
               
                j = 0;
                while (digits[j] <= digits[i]) j++;
                
                swap(digits[j], digits[i]);
                
                sort(begin(digits), begin(digits) + i, greater<int>());
           
                while (digits.size()) {
                    n = n * 10 + digits.back();
                    digits.pop_back();
                    if(n == lmt && digits.front() == 7)
                        return lmt*10+7;
                    
                    if (n >= lmt && digits.size()) return -1;
                }
                 return n > INT_MAX ? -1 : n;
            }
        }
        return -1;
        
    }
};
// 1 2 5 9 3 7

