int lengthOfLastWord(char* s) 
{
    int len = 0;
    
    int last_len = 0;
    
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            if (len > 0)
            {
                last_len = len;
            
                len = 0;
            }
        }
        else
        {
            len++;
        }
        
        s++;
    }
    
    if (len > 0)
    {
        last_len = len;
    }
    
    return last_len;
}