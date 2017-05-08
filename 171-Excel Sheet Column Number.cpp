int titleToNumber(char* s) 
{
    int i;
    int len = strlen(s);
    
    int res = 0;
    for (i = 0; i < len; i++)
    {
        res *= 26;
        
        res += s[i] - 'A' + 1;
    }
    
    return res;
}