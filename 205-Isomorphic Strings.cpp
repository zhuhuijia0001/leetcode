bool isIsomorphic(char* s, char* t) 
{
    int map1[128];
    int map2[128];
    
    int i;
    for (i = 0; i < 128; i++)
    {
        map1[i] = 0;
        map2[i] = 0;
    }
    
    while (*s != '\0')
    {
        if (map1[*s] == 0)
        {
            if (map2[*t] != 0)
            {
                break;
            }
            
            map1[*s] = *t;
            map2[*t] = *s;
        }
        else
        {
            if (*t != map1[*s])
            {
                break;
            }
        }
        
        s++;
        t++;
    }
    
    return *s == '\0';
}