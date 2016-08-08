int climbStairs(int n) 
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    int a, b, tmp;
    
    a = 1;
    b = 1;
    
    int i;
    for (i = 2; i <= n; i++)
    {
        tmp = a;
        a += b;
        
        b = tmp;
    }
    
    return a;
}