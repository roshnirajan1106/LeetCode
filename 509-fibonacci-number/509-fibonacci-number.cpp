class Solution {
public:
    int find(int a,int b, int n)
    {
        if(n == 1)
            return a + b;
        int c = a+b;
        a = b;
        b= c;
        return find(a,b,n-1);
    }
    int fib(int n) {
        if(n == 0 )
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        int a = 0, b=1;
        return find(a,b,n-1);
    }
};