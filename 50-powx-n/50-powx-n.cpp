class Solution {
public:
    
    double find(double x, int n)
    {
        if(n == 0)
            return 1;
        
        if(n % 2 ==0)
        {
            return myPow(x * x ,n/2);
        }
        return x*myPow(x*x,n/2);
            
    }
    double myPow(double x, int n) {
        if(n >= 0)
        {
            return find(x,n);
        }
        n =  -(n +  1); 
        return 1/x*find(1/x,n);
    }
};